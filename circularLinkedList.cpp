#include <iostream>
using namespace std;
struct node 
{
    int data;
    struct node * next;
};
struct node * f=NULL;
void creatingNodes(int n)
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
    last->next=f;
}
void traverse()
{
    struct node * control = f;
    struct node * c = f;
    do{
        cout<<c->data<<endl;
        c=c->next;
    }while(control!=c);

}
int main()
{
    cout<<"Enter the number Elements to be inputed in circular linked list"<<endl;
    int m;
    cin>>m;
    cout<<"Enter the elements"<<endl;
    creatingNodes(m);
    cout<<"The inputed elements in list"<<endl;
    traverse();
}