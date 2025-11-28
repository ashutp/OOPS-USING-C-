#include <iostream>
#include <vector>
using namespace std;
class node
{

public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

node *fun(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }

    node *temp = new node(arr[index]);
    temp->next = fun(arr, index + 1, size);
    return temp;
}

node *sort(node *head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    while (head)
    {
        if (head->data == 0)
        {
            count0++;
        }
        else if (head->data == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }

        head = head->next;
    }

    node *newhead = new node(0);
    node *tail = newhead;

    while (count0)
    {
        tail->next = new node(0);
        tail = tail->next;
        count0--;
    }
    while (count1)
    {
        tail->next = new node(1);
        tail = tail->next;
        count1--;
    }
    while (count2)
    {
        tail->next = new node(2);
        tail = tail->next;
        count2--;
    }

    node *temp = newhead;
    newhead = newhead->next;
    delete temp;
    return newhead;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 2, 0, 1};

    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;

    head = fun(arr, 0, size);
    head = sort(head);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}