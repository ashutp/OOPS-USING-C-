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

node *redupl(node *head)
{
    node *pre = head;
    node *curr = head->next;

    while (curr)
    {
        if (pre->data == curr->data)
        {
            pre->next = curr->next;
            delete curr;
            curr = pre->next;
        }
        else
        {
            pre = curr;
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    int arr[] = {1, 2, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = fun(arr, 0, size);
    head=redupl(head);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}