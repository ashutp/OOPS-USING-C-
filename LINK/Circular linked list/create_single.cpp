#include <iostream>
#include <vector>
using namespace std;
class node
{

public:
    int data;
    node *ptr;
    node(int value)
    {
        data = value;
        ptr = NULL;
    }
};

node *fun(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }

    node *temp = new node(arr[index]);
    temp->ptr = fun(arr, index + 1, size);
    return temp;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = fun(arr, 0, size);
    node *tail = NULL;
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        tail = temp;
        temp = temp->ptr;
    }
    tail->ptr = head;
    tail = tail->ptr;
    while (tail)
    {
        cout << tail->data << endl;
        tail = tail->ptr;
    }

    return 0;
}