#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
};

Node *front = NULL;
Node *rear = NULL;
int Size = 0;

Node *getnode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

bool isEmpty()
{
    return (front == NULL);
}

int size()
{
    return Size;
}

void insertFront(int data)
{
    Node *newNode = getnode(data);

    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        if (front == NULL)
            rear = front = newNode;

        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        Size++;
    }
}

void insertRear(int data)
{
    Node *newNode = getnode(data);
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        if (rear == NULL)
            front = rear = newNode;
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        Size++;
    }
}

void deleteFront()
{
    if (isEmpty())
        cout << "UnderFlow\n";
    else
    {
        Node *temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);

        Size--;
    }
}

void deleteRear()
{
    if (isEmpty())
        cout << "UnderFlow\n";
    else
    {
        Node *temp = rear;
        rear = rear->prev;

        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        free(temp);

        Size--;
    }
}

int getFront()
{
    if (isEmpty())
        return -1;
    return front->data;
}

int getRear()
{
    if (isEmpty())
        return -1;
    return rear->data;
}

void erase()
{
    rear = NULL;
    while (front != NULL)
    {
        Node *temp = front;
        front = front->next;
        free(temp);
    }
    Size = 0;
}

int main()
{
    cout << "Insert element '5' at rear end\n";
    insertRear(5);

    cout << "Insert element '10' at rear end\n";
    insertRear(10);

    cout << "Rear end element: "
         << getRear() << endl;

    deleteRear();
    cout << "After deleting rear element new rear"
         << " is: " << getRear() << endl;

    cout << "Inserting element '15' at front end \n";
    insertFront(15);

    cout << "Front end element: "
         << getFront() << endl;

    cout << "Number of elements in Deque: "
         << size() << endl;

    deleteFront();
    cout << "After deleting front element new "
         << "front is: " << getFront() << endl;

    return 0;
}
