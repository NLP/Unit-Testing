#include <iostream>
#include "../../Grammatica/Syntax-Tree/parser.h"
#include "../../Parser/Tagger/converter.h"
#include "../../Grammatica/cfgq.h"
//#include "../../CONFIG/config.h"
using namespace std;
using namespace NLP;
//Here is where the program is run:
//1. Accept an input sentence from user
//2. Tokenize & Parse
//3. Store into Database /OR/ Extract from Database
//4. Print Result if Necessary

const int MAX = 100;
int main(){
    char input[MAX];
    string sentence;
    STvector S;

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
            Parser P(CFGQ(),Converter(sentence).getWords());

            S = P.parse();
            for(std::size_t i = 0; i < S.size(); ++i){
                //Do stuff here to eliminate trees
            }
            //Do database stuff here
            //Store or extract

            //The answer here

        } catch (const char* e) {
            cout << "something went wrong : " << "Main Driver" << endl;
        }
    }
    cout << endl << "Goodbye!" << endl;
    return 0;
}

