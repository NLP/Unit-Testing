#include <iostream>
#include "../../Parser/Tagger/converter.h"


using namespace NLP;
using namespace std;
void testConverter(Converter& conv, const string& sentence);


int main()
{
    bool done = false;
    // using one instance is better for efficiency
    Converter myConverter;
    string sentence;
    while(!done) {
        cout << "Sentence : ";
        getline(cin, sentence);
        testConverter (myConverter, sentence);
    }
    return 0;
}

/**
 * Test case for Converter class
 * @param none 
 */
void testConverter(Converter &conv, const string &sentence) {
    std::cout << "---   Testing Converter -----\n";
    try {
        conv.setString (sentence);
        vector<NLP::Word> myParsedWords = conv.getWords();

        for(NLP::Word wd: myParsedWords)
            cout << wd << " : " << wd.getRawtypes() << endl;

    } catch (const char* e) {
        cout << "something went wrong : " << "Converter" << endl;
    }
    cout << "-------- End of Converter test case -----\n\n";
}

/** BUG
  * STokenize may not map all characters, if new character is found, just add
  * it to the token.h (UNKNOWN Token feature not working)
  */
