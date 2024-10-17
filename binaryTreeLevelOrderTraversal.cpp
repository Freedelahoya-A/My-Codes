#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node* l;
    node* r;

    node(int d)
    {
        this->data = d;
        this->l = NULL;
        this->r = NULL;
    }
};

node* build(node* root) 
{
    int value;
    cin >> value;

    if (value == -1) 
    {
        return nullptr;
    }
    root = new node(value);
    cout << "Enter left child of " << value << " (-1 for no node): ";
    root->l = build(root->l);
    cout << "Enter right child of " << value << " (-1 for no node): ";
    root->r = build(root->r);
    return root;
}

void levelTraversal(node* root)
{
    cout<<"Level Traversal"<<endl;
    if (root == NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node* currentNode = q.front();
        q.pop();
        if (currentNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << currentNode->data << " ";
            if (currentNode->l)
            {
                q.push(currentNode->l);
            }
            if (currentNode->r)
            {
                q.push(currentNode->r);
            }
        }
    }
}

int main()
{
    node* root = NULL;
    root = build(root);
    levelTraversal(root);
    return 0;
}