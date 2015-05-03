#include <iostream>
#include "../../Parser/Tagger/converter.h"


using namespace NLP;
using namespace std;
void testConverter(Converter& conv, const string& sentence);


int main()
{
    Converter myConverter;
    testConverter(myConverter, "This is a Bear");
    testConverter(myConverter, "That is not a building");       /// Bug , comma in dictionary
    testConverter(myConverter, "Who told you that?");
    testConverter(myConverter, "That's what she said.");
    testConverter(myConverter, "In general, the dative marks the indirect object of a verb, although in some instances, the dative is used for the direct object of a verb pertaining directly to an act of giving something"));
    testConverter(myConverter, "These pronouns are not proper datives anymore in modern English, because they are also used for functions of the accusative."));
    testConverter(myConverter, "Should have will may can could");
    testConverter(myConverter, "Who is making that sounds?");
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
