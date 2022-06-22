#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct TNode
{
    char val;
    TNode *left, *right;
};
//binary tree of symbols
class Tree {
    TNode *root;
    void insert(char a, TNode*& prev);
public:
    Tree():root(nullptr){}

    TNode *getRoot() const;

    void printT(const string& prefix, const TNode* node, bool isLeft);

    friend void input(Tree& h);

    friend ostream &operator<<(ostream &os, Tree h);

};

void findLeafs(vector<TNode*>& leafList, TNode* tmp);



