#include <iostream>
#include "../../Granular-Extractor/Database/OntologyDatabase.h"

using namespace std;

void testOntologyInsertion();

int main()
{
    testOntologyInsertion ();
    return 0;
}

void testOntologyInsertion()
{
    /// testing query
    OntologyDatabase testOntologyDB;
    OntologyDatabase testOntologyDB_two;
    /// Working
//    testOntologyDB.testInsertionQuery ("DELETE from ontology");
//    testOntologyDB.testInsertionQuery ("INSERT INTO ontology(sub, pred, obj) VALUES ('They', 'are' , 'teachers')");
}
