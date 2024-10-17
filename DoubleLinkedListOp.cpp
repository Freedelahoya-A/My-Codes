// MENU:
// 1. Insert the node at a position
// 2. Delete a node from specific position
// 3. Traversal
// 5. Exit
#include <iostream>
using namespace std;

struct node  
{
    struct node *p;
    int data;
    struct node *n;
};

struct node *f = nullptr;

void insertion(int pos, int n) {
    struct node *c = f;
    struct node *newNode = new node;
    newNode->data = n;
    pos=pos-1;
    if (pos == 0) {
        newNode->n = f;
        newNode->p = nullptr;
        if (f != nullptr) {
            f->p = newNode;
        }
        f = newNode;
        return;
    }
    for (int i = 0; i < pos - 1 && c != nullptr; i++) {
        c = c->n;
    }
    if (c == nullptr || c->n == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }
    struct node *next = c->n;
    c->n = newNode;
    newNode->p = c;
    newNode->n = next;
    if (next != nullptr) {
        next->p = newNode;
    }
}

void creatingNodes(int n)
{
    struct node *prev = nullptr;
    struct node *current = nullptr;

    for(int i = 0; i < n; i++)
    {
        current = new node;
        cin >> current->data;

        if(f == nullptr)
        {
            f = current;
            f->p = nullptr;
        }
        else
        {
            current->p = prev; 
            prev->n = current;
        }

        current->n = nullptr;
        prev = current;
    }
}

void traverse()
{
    struct node *s = f;
    while(s != nullptr)
    {
        cout << s->data << endl;
        s = s->n;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements you want to add to the linked list: " << endl;
    cin >> n;
    cout<<"Enter the elements"<<endl;
    creatingNodes(n);
    cout<<"The Linked List Stored is"<<endl;
    traverse();
    cout<<"Enter the element u wanna add"<<endl;
    int n1;
    int pos;
    cin>>n1>>pos;
    insertion(pos,n1);
    cout<<"The element added"<<endl;
    traverse();
    return 0;
}