#include "Tree.h"

void input(Tree& h)
{
    bool flag = true;
    char tmp;
    while(flag)
    {
        cout<<"Enter symbol: ";
        cin>>tmp;
        h.insert(tmp, h.root);
        cout<<"Add another symbol?(Y/N)";
        cin>>tmp;
        if(tmp != 'Y')
            flag = false;
    }
}

ostream &operator<<(ostream &os, Tree h) {
    h.printT("", h.root, false);
    return os;
}

void Tree::printT(const string &prefix, const TNode *node, bool isLeft)
{
    if( node != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "|--" : "'--");

        cout << node->val << std::endl;

        printT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void findLeafs(vector<TNode*>& leafList,TNode* tmp) {
    if(tmp->left == nullptr && tmp->right == nullptr)
        leafList.push_back(tmp);
    else
    {
        if(tmp->left != nullptr)
            findLeafs(leafList,tmp->left);
        if(tmp->right != nullptr)
            findLeafs(leafList,tmp->right);
    }
}

TNode *Tree::getRoot() const {
    return root;
}

void Tree::insert(char a, TNode *&prev)  {
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


