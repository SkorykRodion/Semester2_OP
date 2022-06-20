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
    void insert(char a, TNode*& prev )
    {
        auto cur = new TNode;
        cur->val=a;
        cur->left= nullptr;
        cur->right= nullptr;
        if(prev == nullptr)
            prev = cur;
        else if(cur->val < prev->val)
            insert(a, prev->left);
        else
            insert(a, prev->right);
    }
public:
    Tree():root(nullptr){}

    TNode *getRoot() const;

    void printT(const string& prefix, const TNode* node, bool isLeft);

    friend void input(Tree& h);



    friend ostream &operator<<(ostream &os, Tree h);

};

void findLeafs(vector<TNode*>& leafList, TNode* tmp);



