#include <iostream>
#include "../../Parser/Tagger/converter.h"
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgzero.h"
#include "../../Grammatica/Syntax-Tree/parser.h"
#include "../../Grammatica/Syntax-Tree/syntaxtree.h"
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgq.h"
#include "../../Granular-Extractor/Database/OntologyDatabase.h"
#include "../../Granular-Extractor/Database/CorpusQueryGenerator.h"
#include "../../CONFIG/config.h"
//#include "../../CONFIG/config.h"
using namespace std;
using namespace NLP;
//Here is where the program is run:
//1. Accept an input sentence from user
//2. Tokenize & Parse
//3. Store into Database /OR/ Extract from Database
//4. Print Result if Necessary
void query(Converter& C, const string& s, OntologyDatabase &O);
void ontologize(const string& q, OntologyDatabase &O);
void ontologize(const string &q, string &r, OntologyDatabase &O);

const int MAX = 100;
int main(){
    char input[MAX];
    string sentence;
//    STvector S;
    OntologyDatabase DB;
    Converter C;
    bool type = false;

    cout << "Directions:" << endl;
    cout << "Type in something. (MAX " << MAX << " Characters)" << endl;
    cout << "Don't make any grammar or spelling mistakes" << endl;
    cout << "Press \"x\" or \"X\" to exit" << endl << endl;

    while(true){
        cout << "What is on your mind?" << endl;
        cin.getline(input,MAX);
        sentence = input;

        if(sentence.compare("x") == 0 || sentence.compare("X") == 0)
            break;

        try {
            if(type){
                Converter C(sentence);
                std::vector<Word> test = C.getWords();
                std::set<WordType> t = test.begin()->getTypes();
                cout << "The types of " << sentence << "is: " << endl;
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
    cout << endl << "Goodbye!" << endl;
    return 0;
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
                   break;
               }
               case SentenceType::INTERROGATIVE:{
                   ontologize (stringQuery, tmp_result,O);
                   if(tmp_result.empty())
                       cout << "I don't know." << endl;
                   else  cout << tmp_result << endl;
                   // throw unimplemented_exc();
                   break;
               }
               default:{
                   break;
               }
           }
       } else {
        cout << "I'm sorry Dave, I'm afraid I can't do that" << endl;
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
