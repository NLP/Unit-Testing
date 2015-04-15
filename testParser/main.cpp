#include <iostream>
#include "../../Parser/Tagger/converter.h"

void testConverter();

using namespace std;

int main()
{
    testConverter();
    return 0;
}

/**
 * Test case for Converter class
 * @param none 
 */
void testConverter() {
    std::cout << "---   Testing Converter -----\n";
    try {
        NLP::Converter converted("This is apple"); // Passed

        converted.getWords();

    } catch (const char* e) {
        cout << "something went wrong : " << "Converter" << endl;
    }
    cout << "-------- End of Converter test case -----\n\n";
}
