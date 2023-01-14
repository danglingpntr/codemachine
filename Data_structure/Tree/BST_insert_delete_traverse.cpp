#include <bits/stdc++.h>
using namespace std;

int size;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data{val}, left{nullptr}, right{nullptr} {}
};

Node *insert(Node *head, int data)
{
    if (head == nullptr)
        return new Node(data);
    if (head->data > data)
        head->left = insert(head->left, data);
    else
        head->right = insert(head->right, data);

    return head;
}

struct Node *minValueNode(struct Node *Node)
{
    struct Node *current = Node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deleteNode(struct Node *root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;

        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        //if any of child node of key node is not null
        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void print_inOrder_dfs(Node *root)
{
    if (root == nullptr)
        return;
    print_inOrder_dfs(root->left);
    cout << root->data << " ";
    print_inOrder_dfs(root->right);
    size++;
}

int main()
{
    int N, val,ch;
    cin >> N >> val;
    N--;
    Node *head = insert(nullptr, val);
    while (N--)
    {
        cin >> val;
        insert(head, val);
    }
    cout << "1.Print DFS" << endl << "2.Delete" << endl << "3.MinValue from root" << endl;
    cout << "Enter ch:";
    cin >> ch;
    switch (ch)
    {
    case 1:
        print_inOrder_dfs(head);
        cout << "size:"<<size ;
        break;
    case 2:
        int key;
        cout << "Delete element:" << endl;
        cin >>key ;
        deleteNode(head,key);
        print_inOrder_dfs(head);
        cout << "size:"<<size ; 
        break;
    case 3:
        cout << minValueNode(head)->data<<endl;
        break;
    default:
        cout << "Invalid Choice" << endl;
    }
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