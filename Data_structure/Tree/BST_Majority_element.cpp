#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data,c;
    Node *left , *right;
    Node(int val) : data{val}, left{nullptr}, right{nullptr} {c=1;}
};


Node* insert(Node* head, int data, int& ma)
{
	if (head == NULL) 
	{
		if (ma == 0)
			ma = 1;
		return new Node(data);
	} 

	if(head->data > data)
        head->left = insert(head->left,data, ma);
	else if(head->data < data)
        head->right = insert(head->right,data, ma);
	else
		head->c++;

	ma = max(ma, head->c);

	return head;
}

int inorder(struct Node* root, int s)
{
	static int mx;
	if (root != NULL) 
	{
		inorder(root->left, s);

		if (root->c > (s / 2))
			mx = root->data;

		inorder(root->right, s);
	}
	return mx;
}

int main()
{
	int a[] = { 1, 3, 3, 3, 3, 2 };
	int size = (sizeof(a)) / sizeof(a[0]);

	struct Node* root = NULL;
	int ma = 0;

	for (int i = 0; i < size; i++) {
		root = insert(root, a[i], ma);
	}

	// Function call
	if (ma > (size / 2))
		cout<<"Count:"<<ma << " Element:"<<inorder(root, size);
	else
		cout << "No majority element\n";
	return 0;
}