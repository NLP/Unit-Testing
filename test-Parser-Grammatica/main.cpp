#include <iostream>
#include "../../Parser/Tagger/converter.h"
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgzero.h"
#include "../../Grammatica/Syntax-Tree/parser.h"
#include "../../Grammatica/Syntax-Tree/syntaxtree.h"

using namespace std;

void testParserAndGrammatica(const string& sentence);

int main()
{
//    testParserAndGrammatica("He walks");
//    testParserAndGrammatica("I like cake");
    testParserAndGrammatica("My name is John");
    return 0;
}

/**
 * Test case for ParserAndGrammatica class
 * @param sentence 
 */
void testParserAndGrammatica(const string& sentence) {
    std::cout << "---   Testing ParserAndGrammatica -----\n";
    try {

        Parser P( CFGZero(), Converter(sentence).getWords());

        cout << "Getting the Grammar" << endl;
        cout << P.getGrammar() << endl;

        cout << endl;
        cout << "Parsing the Sentence based on Grammar" << endl;
        STvector S = P.parse();
        for(std::size_t i = 0; i < S.size(); ++i){
            cout << "#" << i+1 << ": " << S[i] << endl;
        }

    } catch (const char* e) {
        cout << "something went wrong : " << "ParserAndGrammatica" << endl;
    }
    cout << "-------- End of ParserAndGrammatica test case -----\n\n";
}
