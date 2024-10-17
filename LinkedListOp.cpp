
// MENU:
// 1. Insert the node at a position
// 2. Delete a node from specific position
// 3. Count
// 4. Traverse
// 5. Search
// 6. Sort
// 7. Reverse
// 8. Exit
#include <iostream>
using namespace std;

struct node 
{
    int data;
    struct node* next;
};

struct node* f = NULL; 

void createNodes(int n)
{
    struct node* current;
    struct node* last = NULL;
    for(int i = 0; i < n; i++)
    {
        current = new node;
        cin >> current->data;
        current->next = NULL;
        if(f == NULL)
        {
            f = current;
            last = f;
        }
        else
        {
            last->next = current;
            last = current;
        }
    }
}
void insertionOfNode(int v, int pos)
{
    struct node* newNode = new node;
    newNode->data = v;
    newNode->next = NULL;
    if(pos == 0) 
    {
        newNode->next = f;
        f = newNode;
        return;
    }
    struct node* n = f;
    for(int i = 0; i < pos - 1 && n != NULL; i++)
    {
        n = n->next;
    }
    if(n != NULL)
    {
        newNode->next = n->next;
        n->next = newNode;
    }
    else
    {
        cout << "Position out of bounds" << endl;
    }
}

void deletionOfNode(int v)
{
    struct node* current = f;
    struct node* prev = NULL;
    if(current != NULL && current->data == v)
    {
        f = current->next;
        delete current;
        return;
    }
    while(current != NULL && current->data != v)
    {
        prev = current;
        current = current->next;
    }
    if(current == NULL) return;
    prev->next = current->next;
    delete current;
}
struct node * ReversingLinkedList()
{
    struct node * c=f;
    struct node * p=NULL;
    struct node * n=NULL;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}
void sorting(int n)
{
    struct node *s = f;
    struct node *r = NULL;
    int temp;
    
    for (int i = 0; i < n-1; i++)
    {
        s = f;
        r = s->next;
        for (int j = 0; j < n-i-1; j++)
        {
            if(s->data > r->data)
            {
                temp = s->data;
                s->data = r->data;
                r->data = temp;
            }
            s = r;
            r = r->next;
        }
    }
}
int countNodes()
{
    struct node* s = f;
    int n = 0;
    while(s != NULL)
    {
        s = s->next;
        n = n + 1;
    }
    return n;
}
void traverse(struct node * s)
{
    cout<<"The linked list is"<<endl;
    struct node * n=s;
    while(n!=NULL)
    {
        cout<<n->data<<endl;
        n=n->next;
    }
    cout<<endl;
}
int main()
{
    cout << "Menu" << endl;
    int choice, value, position, n;
do {
        cout << "1. Create nodes" << endl;
        cout << "2. Insert node" << endl;
        cout << "3. Delete node" << endl;
        cout << "4. Count nodes" << endl;
        cout << "5. Reverse String" << endl;
        cout << "6. Sorting nodes" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the number of nodes to create: ";
                cin >> n;
                createNodes(n);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertionOfNode(value, position);
                traverse(f);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                deletionOfNode(value);
                break;
            case 4:
                cout << "Total nodes: " << countNodes() << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            case 6:
                cout << "The List is being sorted "<< endl;
                sorting(countNodes());
                traverse(f);
                break;
            case 5:
                cout << "The linked list is being reversed" << endl;
                f = ReversingLinkedList();
                traverse(f);
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 7);
    return 0;
}