#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    Tree tree = Tree();
    input(tree);
    cout<<"Tree:\n";
    cout<<tree;
    cout<<"Leafs:";
    vector<TNode*> leafs;
    findLeafs(leafs, tree.getRoot());
    try
    {
        for(auto i: leafs)
            cout<<i->val<<" ";;
    }
    catch(std::exception& e)
    {
        cout<<e.what();
    }

    return 0;
}
