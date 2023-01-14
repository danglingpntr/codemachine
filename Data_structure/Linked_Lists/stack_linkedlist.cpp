#include <iostream>
using namespace std;

class Node
{
   int data;
   Node *next;
   Node *top = NULL;

   public:
   void push(int val);
   void pop();
   void display();
};

void Node::push(int val)
{
    Node *newnode = new Node();
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}

void Node::pop() 
{
    Node *tmp=top;
   if (top == NULL)
      cout << "Stack Underflow" << endl;
   else
   {
      cout << "The popped element is " << top->data << endl;
      top = top->next;
      delete tmp;
   }
}

void Node::display()
{
    Node *ptr;
   if (top == NULL)
      cout << "stack is empty";
   else
   {
      ptr = top;
      cout << "Stack elements are: ";
      while (ptr != NULL)
      {
         cout << ptr->data << " ";
         ptr = ptr->next;
      }
   }
   cout << endl;
}

int main()
{
   int ch, val;
   Node a;
   cout << "1) Push in stack" << endl;
   cout << "2) Pop from stack" << endl;
   cout << "3) Display stack" << endl;
   cout << "4) Exit" << endl;
   do
   {
      cout << "Enter choice: " << endl;
      cin >> ch;
      switch (ch)
      {
      case 1:
         cout << "Enter value to be pushed:" << endl;
         cin >> val;
         a.push(val);
         break;
      case 2:
         a.pop();
         break;
      case 3:
         a.display();
         break;
      case 4:
         cout << "Exit" << endl;
         break;
      default:
         cout << "Invalid Choice" << endl;
      }
   } while (ch != 4);
   return 0;
}