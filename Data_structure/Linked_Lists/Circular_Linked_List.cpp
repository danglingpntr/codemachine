#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void addToEmpty(int data)
{
    if (last != NULL)
        return;

    last = (struct Node *)malloc(sizeof(struct Node));

    last->data = data;
    last->next = last;
}

void addBegin(int data)
{
    if (last == NULL)
        return addToEmpty(data);

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = last->next;
    last->next = temp;
}

void addEnd(int data)
{
    if (last == NULL)
        return addToEmpty(data);

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;
}

void addAfter(int data, int item)
{
    if (last == NULL)
        return;

    struct Node *temp, *p;
    p = last->next;
    do
    {
        if (p->data == item)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;
            return;
        }
        p = p->next;
    } while (p != last->next);

    cout << item << " not present in the list." << endl;
    return;
}

void traverse()
{
    struct Node *p;

    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    p = last->next;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != last->next);
}

int main()
{
    addToEmpty(8);
    addBegin(4);
    addBegin(2);
    addEnd(8);
    addEnd(12);
    addAfter(10, 8);

    traverse();

    return 0;
}