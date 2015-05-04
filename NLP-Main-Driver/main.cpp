#include <iostream>
#include <ctime>
#include <fstream>

#include "../../Grammatica/Syntax-Tree/parser.h"
#include "../../Grammatica/Syntax-Tree/syntaxtree.h"
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgzero.h"
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgq.h"
#include "../../Parser/Tagger/converter.h"
#include "../../Granular-Extractor/Database/OntologyDatabase.h"
#include "../../Granular-Extractor/Database/CorpusQueryGenerator.h"
#include "../../CONFIG/config.h"

using namespace std;
using namespace NLP;

void query(Converter& C, const string& s, OntologyDatabase &O);
void ontologize(const string& q, OntologyDatabase &O);
void ontologize(const string &q, string &r, OntologyDatabase &O);
void hello();
void response(int i);
int rng(int high, int low);
int size(const string s[]);
void printLogin();

const string responses[] = {
    "Of course.", "Very well.", "I understand.", "So what?", "Alright.",
    "I see.", "Ok.", "Yup.", "I'll remember.", "You read my mind.",
    ""
};
const string invalids[] = {
    "I don't know.", //"I don't understand.", "~shurg~", "I need more information.",
    //"Why don't you ask someone else?", "Not enough info.", "I don't recall.",
    //"Who knows?", "No clue.", "Honestly? No idea.", "I have no idea.",
    ""
};
const string ask[] = {
    "What is on your mind?", "Do you have anything to say?", "Anything?", "What do you want to tell me?",
    "Are you going to tell me something?", "What's interesting?", "What's up?",
    "Speak your mind.", "What's happening?", "Well?", "Hmm?",
    ""
};

const int MAX = 100;

int main()
{
    printLogin ();
    srand(time(NULL));
    char input[MAX];
    string sentence;
//    STvector S;
    OntologyDatabase DB;
    Converter C;
    bool type = false;

    hello();

    while(true){
//        cout << ask[rng(size(ask),0)] << endl;
        cout << " >> ";
        cin.getline(input,MAX);
        sentence = input;
        cout << endl;
        if(sentence.compare("x") == 0 || sentence.compare("X") == 0){
            cout << "Goodbye!" << endl << endl;
            break;
        }
        else if(sentence.compare("m") == 0 || sentence.compare("M") == 0){
            cout << "Changing mode " << (type ? "from Type Check to Information"
                                              : "from Information to Type Check")
                    << endl << endl;
            type = !type;
        }
        else{
            try {
                if(type){
                    Converter C(sentence);
                    std::vector<Word> test = C.getWords();
                    std::set<WordType> t = test.begin()->getTypes();
                    cout << "The types of \"" << sentence << "\" is: " << endl;
                    for(std::set<WordType>::iterator it = t.begin(); it != t.end(); ++it){
                        cout << WordStringMap[*it] << endl;
                    }
                }
                else
                    query(C,sentence,DB);

            } catch (const char* e) {
                cout << "something went wrong : " << "Main Driver" << endl;
            }
        }
//        else if



    }
    return 0;
}

void hello(){
    cout << " * Hello! I am Ultron!" << endl;
    cout << " * Please understand that I am only beginning to learn English." << endl;
    cout << " * Thus please refrain from making grammatical and semantical errors when typing, and" << endl;
    cout << " * please type in no more than " << MAX << " characters at a time." << endl;
    cout << " * Tell me a statements or facts that i can understand, and and I will remember." << endl;
    cout << " * Ask me what you've told me and I will try to recall what I remember." << endl;
    cout << " * If you wish to stop, press \"x\" or \"X\"" << endl;
}

void response(int i){
    cout << "Ultron : ";
    if(i > 0){
        cout << responses[rng(size(responses),0)] << endl << endl;
    }
    else if(i < 0){
        cout << invalids[rng(size(invalids),0)] << endl << endl;
    }
    else {
        cout << "I'm sorry Dave, I'm afraid I can't do that." << endl << endl;
    }

}

int rng(int high, int low){
    return (rand() % (high - low)) + low;
}

int size(const string s[]){
    int i = 0;
    while(s[i] != "") ++i;
    return i;
}

void query(Converter& C, const string& s, OntologyDatabase& O){
   try {
       C.setString (s);
       Parser P(CFGQ() , C.getWords ());
       STvector S = P.parse ();
       string stringQuery;
       QueryGenerator myQry;
       if(!S.empty ()) {
           stringQuery = myQry.getQueryOf (S[0]);
           string tmp_result; /// For interrogative sentence, a reply is needed
           switch (S[0].getSentenceType()){
               case SentenceType::DECLARATIVE:{
                   ontologize (stringQuery,O);
//                   response(1);
                   break;
               }
               case SentenceType::INTERROGATIVE:{
                   ontologize (stringQuery, tmp_result,O);
                   if(tmp_result.empty())
                       response(-1);
                   else  cout << "Ultron : " << tmp_result << endl;
                   // throw unimplemented_exc();
                   break;
               }
               default:{
                   break;
               }
           }
       } else {
            response(0);
       }
   } catch (const exception &e) {
       cout << e.what() << endl;
   }

}

void ontologize(const string& q, OntologyDatabase& O){
     O.InsertionQuery (q);
}
void ontologize(const string &q, string &r, OntologyDatabase &O){
    O.QuestionQuery (q, r); /// modify result
}

void printLogin()
{
    string line;
    ifstream myfile("../ultron.txt");
    if (myfile.is_open())
    {
      while ( getline (myfile,line) )
        cout << line << '\n';
      myfile.close();
    }
}
