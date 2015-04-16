#include <iostream>
#include "../../Parser/Tagger/converter.h"

void testConverter(string sentence);

using namespace std;

int main()
{
    testConverter("This is a Bear");
    testConverter("That is not a building");       /// Bug , comma in dictionary
    testConverter("Who told you that?");
//    testConverter("That's what she said.");
    return 0;
}

/**
 * Test case for Converter class
 * @param none 
 */
void testConverter(string sentence) {
    std::cout << "---   Testing Converter -----\n";
    try {

        NLP::Converter converted(sentence); // Passed
        list<NLP::Word> myParsedWords = converted.getWords();
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
