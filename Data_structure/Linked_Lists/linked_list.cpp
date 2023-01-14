#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   struct Node *next;
} ;

Node *head=NULL;

void push_begining(int val) //Create list / push at the begining
{
   struct Node *newnode = new Node;
   newnode->data = val;
   newnode->next = head;
   head = newnode;
}

void push_end(int val) //Push at the end
{
   if (head == NULL)
      push_begining(val);
   else
   {
      struct Node *newNode, *temp;
      newNode = (struct Node *)malloc(sizeof(struct Node));
      newNode->data = val;
      newNode->next = NULL;
      temp = head;

      while (temp->next != NULL) // Traverse to the last node
         temp = temp->next;

      temp->next = newNode;
   }
}

void pop() // delete Node from begining
{
   struct Node *toDelete = head;
   if (head == NULL)
      cout << "Stack Underflow" << endl;
   else
   {
      cout << "The popped element is " << head->data << endl;
      head = head->next;
      free(toDelete);
   }
}

void insertNodeAtMiddle(int data, int position)
{
   if (head == NULL)
   {
      cout << "STACK UNDERFLOW" << endl;
      return;
   }
   
   int i;
   struct Node *newNode, *temp;
   temp = head;
   newNode = (struct Node *)malloc(sizeof(struct Node));

   if (newNode == NULL)
      cout << "Unable to allocate memory.";
   else
   {
      for (i = 2; i <= position - 1; i++) //Traverse to the n-1 position
      {
         temp = temp->next;
         if (temp == NULL)
            {
               break;
            }
      }

      if (temp != NULL)
      {
         newNode->data = data;
         newNode->next = temp->next; /* Link address part of new node */
         temp->next = newNode;       /* Link address part of n-1 node */
      }
      else
         cout << "UNABLE TO INSERT DATA AT THE GIVEN POSITION\n";
   }
}

void deleteNode(int key)
{
   // Store head node
   Node *temp = head;
   Node *prev = NULL;

   if (temp == NULL)
      return;

   if (temp->data == key)
   {
      head = temp->next;
      delete temp;
      return;
   }
   else
   {
      while (temp->data != key && temp->next!=NULL)
      {
         prev = temp;
         temp = temp->next;
      }
      // Unlink the node from linked list
      prev->next = temp->next;

      // Free memory
      delete temp;
   }
}

void reverse()
{
   // Initialize current, previous and next pointers
   Node *current = head;
   Node *prev = NULL, *next = NULL;

   while (current != NULL)
   {
      next = current->next;
      current->next = prev; 
      prev = current;
      current = next;
   }
   head = prev;

   struct Node *temp = head;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
}

void deleteAtPos(int position)
{
   if (head == NULL)
   {
      cout << "STACK UNDERFLOW" << endl;
      return;
   }

   if(position==1)
   {
      pop();
      return;
   }

   struct Node *temp = head; 
   for (int i = 2; i < position; i++) //Traverse to the n-1 position
   {
      temp = temp->next;
      if (temp == NULL)
         break;
   }
   Node *toDelete = temp->next;
   if (temp != NULL)
      temp->next = temp->next->next;
   else
      cout << "No element there\n";

   free(toDelete);
}

void deleteLastNode()
{
   struct Node *toDelete, *secondLastNode;

   if (head == NULL)
      printf("List is already empty.");
   else
   {
      toDelete = head;
      secondLastNode = head;

      while (toDelete->next != NULL) /* Traverse to the last node of the list */
      {
         secondLastNode = toDelete;
         toDelete = toDelete->next;
      }
   }
   if (toDelete == head)
      head = NULL;
   else
      secondLastNode->next = NULL; /* Disconnect link of second last node with last node */

   cout << "Successfully deleted:" << toDelete->data << endl;
   free(toDelete); /* Delete the last node */
}

void display()
{
   struct Node *ptr;
   if (head == NULL)
      cout << "stack is empty";
   else
   {
      ptr = head;
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
   int ch, val, pos;
   cout << "1) Push in begining/PUSH" << endl;
   cout << "2) Push in end" << endl;
   cout << "3) Push in position" << endl;
   cout << "4) Delete Last Node" << endl;
   cout << "5) Delete First Node/POP" << endl;
   cout << "6) Delete At Position" << endl;
   cout << "7) Delete At Position" << endl;
   cout << "8) reverse" << endl;
   cout << "9) Display" << endl;
   cout << "10) Exit" << endl; 
   do
   {
      cout << "Enter ch:";
      cin >> ch;
      switch (ch)
      {
      case 1:
         cout << "Enter value to be pushed:" << endl;
         cin >> val;
         push_begining(val);
         break;
      case 2:
         cout << "Enter value to be pushed:" << endl;
         cin >> val;
         push_end(val);
         break;
      case 3:
         cout << "Push at Position:" << endl;
         cin >> pos;
         cout << "Data:" << endl;
         cin >> val;
         insertNodeAtMiddle(val, pos);
         break;
      case 4:
         deleteLastNode();
         break;
      case 5:
         pop();
         break;
      case 6:
         cout << "Delete at Position:" << endl;
         cin >> pos;
         deleteAtPos(pos);
         break;
      case 7:
         cout << "Delete Key:" << endl;
         cin >> pos;
         deleteNode(pos);
         break;
      case 8:
         reverse();
         break;
      case 9:
         display();
         break;
      case 10:
         cout << "Exit" << endl;
         break;
      default:
         cout << "Invalid Choice" << endl;
      }
   } while (ch != 10);
   return 0;
}