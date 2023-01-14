#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left , *right;
    Node(int val) : data{val}, left{nullptr}, right{nullptr} {}
};

Node* insert(Node* head, int data)
{
    if(head==nullptr) return new Node(data);
    if(head->data > data)
        head->left = insert(head->left,data);
    else
        head->right = insert(head->right,data);

    return head;
} 

bool isBST (Node* head, int min, int max)
{
    if (head == NULL)
        return true;

    if (head->data <= min || head->data > max)
        return false;

    return isBST(head->left,min,head->data) && isBST(head->right,head->data,max) ;
}

int main()
{
    int N , val;
    cin >> N >> val;
    N--;
    Node *head = insert(nullptr,val);
    while (N--)
    {
        cin>> val;
        insert(head,val); 
    }
    cout << isBST(head,INT_MIN,INT_MAX);
    return 0;
}

// 7
// 5
// 2
// 3
// 9
// 1
// 8
// 7

/*       5
       /    \
     2        9 
   /  \      /  
  1    3    8     
           /  
          7   */