#include <iostream>
#include "../../Grammatica/Grammar Structure/Grammar-with-Map/cfgzero.h"
#include "../../Grammatica/Syntax-Tree/parser.h"
#include "../../Grammatica/Syntax-Tree/syntaxtree.h"

using namespace std;

void testTN();
void testTree();
void testSyntax();
void testParser();

int main()
{

//    testTN();

//    testTree();
//    testSyntax();
    testParser();
    return 0;
}

void
testTN()
{
    //Testing TreeNode Functions
    cout << "Initialized TreeNode with 4" << endl;
    TreeNode<int>* tr = new TreeNode<int>(4);
    cout << *tr << endl;

    cout << "Added Child 5" << endl;
    tr->addChild(5);
    cout << *tr << endl;
    cout << "Added Child 6" << endl;
    tr->addChild(6);
    cout << *tr << endl;
    cout << "Added Child 7" << endl;
    tr->addChild(7);
    cout << *tr << endl;

    cout << "The Children of 4" << endl;
    for(std::size_t i = 0; i < tr->children().size(); ++i){
        cout << *tr->children()[i] << "|";
    }
    cout << endl;

    cout << "Set Data of TreeNode to 10 from 4" << endl;
    tr->setData(4);
    cout << *tr << endl;

    cout << "Change children to 1,2,3" << endl;
    tr->setChildren({new TreeNode<int>(1),new TreeNode<int>(2),new TreeNode<int>(3)});
    cout << *tr << endl;

    //Testing Exterior TreeNode Functions of rt
    cout << "Copy the treeNode" << endl;
    TreeNode<int>* copy = rt::copy(tr);
    cout << tr << ": " << *tr << endl;
    cout << copy << ": " << *copy << endl;

    cout << "Clearing the copy" << endl;
    rt::clear(copy);
    cout << copy << endl;
    cout << *tr << endl;

    cout << "The size of tr" << endl;
    cout << rt::size(tr) << endl;
    cout << *tr << endl;

    cout << "Number of leaves of tr" <<endl;
    cout << rt::leaves(tr) << endl;
    cout << *tr << endl;

    cout << "Search for 3 in tr" << endl;
    cout << *rt::search(tr,3) << endl;

    cout << "Parent of 3 in tr" << endl;
    cout << *rt::parent(tr,rt::search(tr,3)) << endl;

    cout << "Vector of Leaves of tr" << endl;
    for(std::size_t i = 0; i < rt::allLeaves(tr).size(); ++i){
        cout << *rt::allLeaves(tr)[i] << "|";
    }
    cout << endl;
}


void
testTree()
{
    Tree<int> T;
    cout << "Add 10" << endl;
    T.addHere(10);
    cout << T << endl;
    cout << "Add 5 to 10" << endl;
    T.addHere(5);
    cout << T << endl;
    cout << "Add 15 to 10" << endl;
    T.addHere(15);
    cout << T << endl;
    cout << "Add 25 to 10" << endl;
    T.addHere(25);
    cout << T << endl;

    cout << "Add 30 to 15" << endl;
    T.addNode(T.search(15),30);
    cout << T << endl;

    cout << "This is current: " << endl;
    cout << *T.getCurrent() << endl;

    cout << "Shifting Current down to 25" << endl;
    T.shiftDown(2);
    cout << *T.getCurrent() << endl;

    cout << "Add 0 to 25" << endl;
    T.addHere(0);
    cout << T << endl;

    cout << "Search for 5" << endl;
    cout << *T.search(5) << endl;

    cout << "Set current to 3" << endl;
    T.set(3);
    cout << T << endl;

    cout << "Number of leaves" << endl;
    cout << T.leafNum() << endl;

    cout << "Shift to Root" << endl;
    T.shiftToRoot();
    cout << *T.getCurrent() << endl;

    cout << "Number of children of root" << endl;
    cout << T.childNum() << endl;
}


void
testSyntax()
{
    SyntaxTree T;
    cout << T << endl;

    cout << "Add Def of S->NP VP" << endl;
    T.addDef({NOUNPHRASE,VERBPHRASE});
    cout << T << endl;

    cout << "Remove Def of S" << endl;
    T.removeDef();
    cout << T << endl;

    cout << "Readding S->NP VP" << endl;
    T.addDef({NOUNPHRASE,VERBPHRASE});

    cout << "Get the Def of S" << endl;
    for(std::size_t i = 0; i < T.getDef().size(); ++i){
        cout << phraseLookUp[T.getDef()[i]] << "|";
    }
    cout << endl;

    cout << "Get Phrase of S" << endl;
    cout << phraseLookUp[T.getPhrase()] << endl;

    cout << "Get First Leaf" << endl;
    cout << *T.getFirstLeaf() << endl;

    cout << "Get Last Leaf" << endl;
    cout << *T.getLastLeaf() << endl;

    cout << "Add NP->D N" << endl;
    T.shiftDown(0);
    T.addDef({DETERMINER,NOUN});
    cout << T << endl;

    cout << "Get the leaves before VP" << endl;
    T.shiftUp();
    T.shiftDown(1);
    cout << *T.getCurrent() << endl;
    cout << T.leavesBefore() << endl;

    cout << "Testing assignHeads" << endl;
    T.assignHeads();
    cout << T << endl;
}


void
testParser()
{
    CFGZero Z;
    Wvector W;
    W.insert(W.end(),
//            {Word(Token("The",ALPHA),{determiner}),
//             Word(Token("cat",ALPHA),{noun}),
//             Word(Token("ate",ALPHA),{verb}),
//             Word(Token("an",ALPHA),{determiner}),
//             Word(Token("apple",ALPHA),{noun}),
//             Word(Token("on",ALPHA),{preposition}),
//             Word(Token("the",ALPHA),{determiner}),
//             Word(Token("tree",ALPHA),{noun})
//            {Word(Token("John",ALPHA),{verb,noun}),
//             Word(Token("kicks",ALPHA),{verb}),
//             Word(Token("ball",ALPHA),{noun}),
//             Word(Token("to",ALPHA),{preposition}),
//             Word(Token("Mark",ALPHA),{noun})
            {Word(Token("He",ALPHA),{noun}),
             Word(Token("walks",ALPHA),{verb})
             });
    Parser P(Z,W);
    cout << "Getting the Grammar" << endl;
    cout << P.getGrammar() << endl;

    cout << "Getting the Words" << endl;
    for(std::size_t i = 0; i < P.getSentence().size(); ++i){
        cout << P.getSentence()[i] << "|";
    }
    cout << endl;

    cout << "Parsing the Sentence based on Grammar" << endl;
    STvector S = P.parse();
    for(std::size_t i = 0; i < S.size(); ++i){
        cout << "#" << i+1 << ": " << S[i] << endl;
    }
    cout << endl;
}
