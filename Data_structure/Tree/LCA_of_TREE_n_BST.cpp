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

Node *lca(Node *root, int v1 , int v2)                      //Gerenal Approach for an TREE
{   
    if (!root)
        return nullptr;
    
    if(root->data == v1 || root->data == v2)
        return root;
    
    Node *llca = lca(root->left, v1, v2);
    Node *rlca = lca(root->right, v1, v2);

    if (llca && rlca)
        return root;
    
    return llca? llca : rlca;
}

Node *bstLca(Node *root, int v1, int v2)                     //*ONLY FOR BST*
{      
    if(root->data < v1 && root->data < v2)
        return bstLca(root->right,v1,v2);
    if(root->data > v1 && root->data > v2)
        return bstLca(root->left,v1,v2);
        
    return root;
}


int main()
{
    int N , val,a ,b;
    cin >> N >> val;
    N--;
    Node *head = insert(nullptr,val);
    while (N--)
    {
        cin>> val;
        insert(head,val); 
    }
    cout<<"enter element for which lca needs to be find:"; cin >> a >> b;
    cout << lca(head,a,b)->data<<" ";cout << bstLca(head,a,b)->data;
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