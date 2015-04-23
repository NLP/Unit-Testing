#include <iostream>
#include "../../Parser/Tagger/converter.h"

void testConverter(string sentence);

using namespace std;

int main()
{
//    testConverter("Those octopi looked delicious"); // fix this, it resulted in 'O'
    testConverter("Those apples looked delicious");
    testConverter("Do you have some matches?");
    testConverter("Who have some machetes?");
//    testConverter("This is a Bear");
//    testConverter("That is not a building");       /// Bug , comma in dictionary
//    testConverter("Who told you that?");
//    testConverter("That's what she said.");
//    testConverter("In general, the dative marks the indirect object of a verb, although in some instances, the dative is used for the direct object of a verb pertaining directly to an act of giving something");
//    testConverter("These pronouns are not proper datives anymore in modern English, because they are also used for functions of the accusative.");
//   testConverter("I like burgers.");
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
