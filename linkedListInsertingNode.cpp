#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node * next;
};
struct node * first = NULL;
struct node * last = NULL;
void insertAtAnyposition(int val,int pos)
{
    struct node * newNode = new node;
    struct node * d = first;
    newNode->data = val;
    int count = 0;
    while(d != NULL)
    {
        count++;
        if(count != pos-1)
        {
            d = d->next;
        }
        else
        {
            newNode->next = d->next;
            d->next = newNode;
        }
    }
}
void insertAtBegining(int val)
{
    struct node * f = first;
    struct node * newNode = new node;
    newNode->data = val;
    newNode->next = f;
    f = newNode;
}
void insertAtEnd(int val)
{
    struct node * newNode = new node;
    struct node * last;
    newNode->data = val;
    if(first == first)
    {
        first = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}