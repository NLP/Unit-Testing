#include <iostream>
#include "../../Parser/Tagger/converter.h"
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgzero.h"
#include "../../Grammatica/Syntax-Tree/parser.h"
#include "../../Grammatica/Syntax-Tree/syntaxtree.h"
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgq.h"
#include "../../Granular-Extractor/Database/OntologyDatabase.h"
#include "../../Granular-Extractor/Database/CorpusQueryGenerator.h"
#include "../../CONFIG/config.h"

using namespace std;

void testQueryGenerator(Converter& conv, const string& sentence);
void testOntologyInsertion(const string& query);/// @note PASSED
void testOntologyQuestion (const string& query, string &result);

int main()
{
    bool done = false;
    // using one instance is better for efficiency
    Converter myConverter;
    string sentence;
    while(!done) {
        cout << "Sentence : ";
        getline(cin, sentence);
        testQueryGenerator (myConverter, sentence);
    }
    return 0;
}



/**
 * Test case for QueryGenerator class
 * @param none
 */
void testQueryGenerator(Converter &conv, const string &sentence) {
    std::cout << "---   Testing QueryGenerator -----\n";
    try {
        conv.setString (sentence);
        Parser P(CFGQ() , conv.getWords ());
        STvector S = P.parse ();
        cout << "Tree found : " << S.size () << endl;
        /// for now, make sure vector only have 1 SyntaxTree
        string stringQuery;
        QueryGenerator myQry;
        if(!S.empty ()) {
            cout << "DEBUG(type) : " << sentenceLookUp[S[0].getSentenceType()] << endl;

            /// Here, query command will be generated based on SentenceType
            stringQuery = myQry.getQueryOf (S[0]);

            /// Phase 2 : Insertion or Request
            string tmp_result; /// For interrogative sentence, a reply is needed
            switch (S[0].getSentenceType())
            {
            case SentenceType::DECLARATIVE:
                cout << " Inserting to database : " << endl;
                testOntologyInsertion (stringQuery);
                break;
            case SentenceType::INTERROGATIVE:
//                SyntaxObject askFor = S[0].askingFor(); /// need to to find out if Interrogative question is yes/no or asking value
                testOntologyQuestion (stringQuery, tmp_result);
                /// Is there any relationship found from the table?
                if(S[0].askingFor() == SyntaxObject::AUX)
                    tmp_result = (tmp_result.empty () ? "No" : "Yes");
                cout << ">> " << tmp_result << endl;
                break;
            default:
                throw unimplemented_exc();
                break;
            }

        } else {
            cout << "I'm sorry Dave, I'm afraid I can't do that" << endl;
        }

    } catch (const exception &e) {
        cout << e.what() << endl;
    }
    cout << "-------- End of QueryGenerator test case -----\n\n";
}



 //// @note PASSED
void testOntologyInsertion(const string &query)
{
    /// testing query
    OntologyDatabase testOntologyDB;
    /// Working
    testOntologyDB.InsertionQuery (query);
}

/// @note TESTING. ...
void testOntologyQuestion (const string& query, string& result)
{
    OntologyDatabase testDB;
    testDB.QuestionQuery (query, result); /// modify result
}
