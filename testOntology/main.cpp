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
//    testOntologyInsertion ();
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
            stringQuery = myQry.getQueryOf (S[0]);
        } else {
            cout << "Sorry, no sensible structure found" << endl;
            throw unimplemented_exc();
        }
        cout << "result : " << stringQuery << endl;
        /// Phase 2 : Insertion to database
        cout << " Inserting to database : " << endl;
        testOntologyInsertion (stringQuery);
    } catch (const char* e) {
        cout << "something went wrong : " << "QueryGenerator" << endl;
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
//    OntologyDatabase testOntologyDB_two;
    /// Working
//    testOntologyDB.testInsertionQuery ("DELETE from ontology");
//    testOntologyDB.testInsertionQuery ("INSERT INTO ontology(sub, pred, obj) VALUES ('They', 'are' , 'teachers')");
    testOntologyDB.testInsertionQuery (query);
}
