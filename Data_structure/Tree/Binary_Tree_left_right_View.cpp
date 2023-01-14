#include <bits/stdc++.h>
using namespace std;

int maxLevel;

struct Node 
{
    int data;
    Node *left , *right;
    Node(int val) : data{val}, left{nullptr}, right{nullptr} {}
};

void print_leftView_postOrder_dfs(Node* root,int &max_levl, int current_levl)  // Pre Order trverse (R L R)  
                                                                              //(R= right node , L= left Ndoe, R =root) 
{
    if (root == nullptr)
        return;
    
    if(current_levl>max_levl) 
    {
        cout<< root->data << " "; 
        max_levl=current_levl;
    }
    print_leftView_postOrder_dfs(root->left,max_levl,current_levl+1);     
    print_leftView_postOrder_dfs(root->right,max_levl,current_levl+1);
}

void print_rightView_postOrder_dfs(Node* root,int &max_levl, int current_levl) 
{
    if (root == nullptr)
        return;

    if(current_levl>max_levl) 
    {
        cout<< root->data << " "; 
        max_levl=current_levl;
    }
    print_rightView_postOrder_dfs(root->right,max_levl,current_levl+1);
    print_rightView_postOrder_dfs(root->left,max_levl,current_levl+1);     
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(7);
    root->right->left = new Node(6);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(10);
    root->right->left->left->right = new Node(12);
    int a=-1;
    print_leftView_postOrder_dfs(root,a,0); 
    a=-1;
    print_rightView_postOrder_dfs(root->right,a,0);        
    delete root->right->right, root->right->left, root->left->right, root->left->left, root->right, root->left;
    return 0;
}

/*         1
       /       \
     2           3
    /  \         /
   4    5       6  
        \     /  \ 
         7   9   10    
           \
            12    */
    