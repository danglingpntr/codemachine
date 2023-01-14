#include <bits/stdc++.h>                                // Formula for left and right node 
using namespace std;        //When array storing from 1 // Left = 2*parent_Pos  Right=(2*parent_Pos)+1
                            //When array storing from 0 // Left = (2*parent_Pos)+1  Right=(2*parent_Pos)+2
char tree[10];

void root(int key)
{
    if (tree[1] != '\0')
        cout <<"Tree already have root"<<endl;
    else
        tree[1] = key;     
}

void set_left(char key, int parent)
{
    if(tree[parent]=='\0')
        cout <<"can't set left child at:"<< (2*parent) << ", no parent found" << endl;
    else
        tree[2*parent]=key;
}

void set_right(char key, int parent)
{
    if(tree[parent]=='\0')
        cout <<"can't set left child at:"<< (2*parent)+1 << ", no parent found" << endl;
    else
        tree[(2*parent)+1]=key;
}

void print_tree()
{
    for(int i=0; i<10; i++)
    {
        if (tree[i]!= '\0')
            cout << tree[i];
        else 
            cout << '_';
    }
}

int main()
{
    root('A');
    set_left('B',1);
    set_right('C',1);
    set_left('D',2);
    set_right('E',2);
    set_right('F',3);
    print_tree();
    return 0;
}

/*       1(A)
       /   \
     2(B)   3(C)
   /  \        \
 4(D)  5(E)     7(F) */