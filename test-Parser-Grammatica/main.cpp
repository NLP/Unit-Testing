#include <iostream>
#include "../../Parser/Tagger/converter.h"
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgzero.h"
#include "../../Grammatica/Syntax-Tree/parser.h"
#include "../../Grammatica/Syntax-Tree/syntaxtree.h"
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgq.h"

using namespace std;

void testParserAndGrammatica(const string& sentence);

int main()
{
    testParserAndGrammatica("He walks");
    testParserAndGrammatica("I like cake");
    testParserAndGrammatica("My name is John");
    testParserAndGrammatica("Who are you");
    testParserAndGrammatica("Did you eat"); //Gotta add did, does, do; have, had; am, are, is for aux
    testParserAndGrammatica("Is John kick the ball");
    testParserAndGrammatica("Why should I give you a sentence"); //Why needs to be its own class.. what is should recognized as?
    testParserAndGrammatica("You are putting me on the spot");
    testParserAndGrammatica("That was not complicated"); //What type is that, and not?
    testParserAndGrammatica("The man sent a letter to his son"); //His needs to be included as a determiner
    testParserAndGrammatica("The man sends a letter to a son");
    testParserAndGrammatica("Is he die"); //Did?
    testParserAndGrammatica("Wa he kicked"); //was also should be added as an aux, also what is considered a noun
    testParserAndGrammatica("What did John kick to Mark");
    testParserAndGrammatica("Are you here");

    return 0;
}

/**
 * Test case for ParserAndGrammatica class
 * @param sentence 
 */
void testParserAndGrammatica(const string& sentence) {
    std::cout << "---   Testing ParserAndGrammatica -----\n";
    try {

        Parser P(CFGQ() , Converter(sentence).getWords());

//        cout << "Getting the Grammar" << endl;
//        cout << P.getGrammar() << endl;
        cout << "Sentence: " << sentence << endl;
        cout << endl;
        cout << "Parsing the Sentence based on Grammar" << endl;
        STvector S = P.parse();
        for(std::size_t i = 0; i < S.size(); ++i){
            cout << "SENTENCE TYPE: " << sentenceLookUp[S[i].getSentenceType()] << endl;
            cout << "#" << i+1 << ": " << S[i] << endl;
        }

    } catch (const char* e) {
        cout << "something went wrong : " << "ParserAndGrammatica" << endl;
    }
    cout << "-------- End of ParserAndGrammatica test case -----\n\n";
}
