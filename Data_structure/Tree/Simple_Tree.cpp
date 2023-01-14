#include <bits/stdc++.h>
using namespace std;
int sum;

struct Node 
{
    int data;
    Node *left , *right;
    Node(int val) : data{val}, left{nullptr}, right{nullptr} {}
};

void print_preOrder_dfs(Node* root)                                // Pre Order trverse (R L R)  (R= right node , L= left Ndoe, R =root) 
{
    if (root == nullptr)
        return;
    cout<< root->data << " ";
    print_preOrder_dfs(root->left);
    print_preOrder_dfs(root->right);
}

void print_inOrder_dfs(Node* root)
{
    if (root == nullptr)
        return;
    print_inOrder_dfs(root->left);
    cout<< root->data << " ";
    print_inOrder_dfs(root->right);
}

void print_postOrder_dfs(Node* root)
{
    if (root == nullptr)
        return;
    print_postOrder_dfs(root->left);
    print_postOrder_dfs(root->right);
    sum+=root->data ;
    cout<< root->data << " ";
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout <<"Pre order "; print_preOrder_dfs(root); cout << endl;
    cout <<"in order " ; print_inOrder_dfs(root); cout << endl;
    cout <<"Post order " ; print_postOrder_dfs(root); cout << endl <<"sum:"<<sum;
    delete root->right->right, root->right->left, root->left->right, root->left->left, root->right, root->left;
    return 0;
}

/*       1
       /   \
     2       3
   /  \     /  \
 4     5   6    7 */
    