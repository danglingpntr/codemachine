#include <bits/stdc++.h>
//#include <cinttypes>
 
using namespace std;

class Node {
    public:
    int data;
    Node* xnode;
};
 
Node* Xor(Node* x, Node* y)
{
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

void insert(Node** head_ref, int data)
{
    // Allocate memory for new node
    Node* new_node = new Node();
    new_node -> data = data;
 
    // Since new node is inserted at the
    // start , xnode of new node will always be
    // Xor of current head and NULL
    new_node -> xnode = *head_ref;
 
    // If linkedlist is not empty, then xnode of
    // present head node will be Xor of new node
    // and node next to current head */
    if (*head_ref != NULL) 
    {
        // *(head_ref)->xnode is Xor of (NULL and next).
        // If we Xor Null with next we get next
        (*head_ref)->xnode = Xor(new_node, (*head_ref)->xnode);
    }
 
    // Change head
    *head_ref = new_node;
}
 
void printList(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
 
    cout << "The nodes of Linked List are: \n";
 
    // Till condition holds true
    while (curr != NULL) {
        // print current node
        cout << curr -> data << " ";
 
        // get address of next node: curr->xnode is
        // next^prev, so curr->xnode^prev will be
        // next^prev^prev which is next
        next = Xor(prev, curr -> xnode);
 
        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
}
 

int main()
{
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 100);
    insert(&head, 1000);
    insert(&head, 10000);
 
    // Printing the created list
    printList(head);
 
    return (0);
}