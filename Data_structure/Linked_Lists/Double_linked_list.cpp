//doubly linked list

#include <bits/stdc++.h>
using namespace std;
 
// A linked list node
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void push(int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;

    new_node->prev = NULL;

    if (head != NULL)
        head->prev = new_node;

    head = new_node;
}

void insertAfter(int position, int new_data)
{
    if(head==NULL)
      {cout<<"STACK UNDERFLOW"<<endl; return;}

    Node* new_node = new Node();
    Node* temp = head;

    for (int i = 2; i <= position - 1; i++) //Traverse to the n-1 position
    {
        temp = temp->next;
        if (temp == NULL)
            break;
    }

    if (temp != NULL)
    {
        new_node->data = new_data;
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;

        if (new_node->next != NULL)
            new_node->next->prev = new_node;
    }
    else
        cout << "UNABLE TO INSERT DATA AT THE GIVEN POSITION\n";
} 

void deleteAtPos(int position)
{
    if(head==NULL)
      {cout<<"STACK UNDERFLOW"<<endl; return;}

    Node* temp= head;

    for (int i = 2; i <= position - 1; i++) //Traverse to the n-1 position
    {
        temp = temp->next;
        if (temp == NULL)
            break;
    }
    
    if (temp != NULL)
    {
        Node* tempPrev=temp, *toDelete;
        toDelete = temp->next;
        temp->next = temp->next->next;
        temp=temp->next;
        temp->prev = tempPrev;
        free(toDelete);
    }
    else
        cout << "No element there\n";
}

void append(int new_data)
{
    if (head == NULL)
        push(new_data);
    else
    {
        Node *new_node = new Node();
        Node *last = head;

        new_node->data = new_data;
        new_node->next = NULL;

        while (last->next != NULL)
            last = last->next;

        last->next = new_node;
        new_node->prev = last;
    }
    return;
}

void printList()
{
    Node *last, *node;
    node = head;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";
        last = node;
        node = node->next;
    }
 
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<<last->data<<" ";
        last = last->prev;
    }
}

int main()
{
    push(7);
    push(1);
    append(4);
    insertAfter(4, 8);
    deleteAtPos(2);             //deletes 7
 
    cout << "Created DLL is: ";
    printList();
 
    return 0;
}
 