#include <bits/stdc++.h>
using namespace std;

struct QNode
{
    int data;
    QNode *next;
};

QNode *front = NULL, *rear = NULL;

void enQueue(int x)
{
    QNode *temp = new QNode();

    if (rear == NULL)
    {
        front = rear = temp;
        return;
    }
    temp->data=x;
    rear->next = temp;
    rear = temp;
}

void deQueue()
{
    if (front == NULL)
        return;

    QNode *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete (temp);
}

int main()
{
    enQueue(10);
    enQueue(20);
    deQueue();
    deQueue();
    enQueue(30);
    enQueue(40);
    enQueue(50);
    deQueue();
    cout << "Queue Front : " << front->data << endl;
    cout << "Queue Rear : " << rear->data;
}