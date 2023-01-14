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

void invertTree(Node* root)
{
    if (root == nullptr)
        return;

    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
}

void print_inOrder_dfs(Node* root)
{
    if (root == nullptr)
        return;
    print_inOrder_dfs(root->left);
    cout<< root->data << " ";
    print_inOrder_dfs(root->right);
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
    invertTree(head);
    print_inOrder_dfs(head);
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
     9        2 
   /        /  \
  8        3    1 
 /            
7               */