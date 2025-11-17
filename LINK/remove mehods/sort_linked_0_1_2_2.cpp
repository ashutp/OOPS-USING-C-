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
    node *head0 = new node(0);
    node *head1 = new node(0);
    node *head2 = new node(0);
    node *temp0 = head0;
    node *temp1 = head1;
    node *temp2 = head2;

    while (head)
    {
        if (head->data == 0)
        {
            temp0->next = head;
            head = head->next;
            temp0 = temp0->next;
        }
        else if (head->data == 1)
        {
            temp1->next = head;
            head = head->next;
            temp1 = temp1->next;
        }
        else
        {
            temp2->next = head;
            head = head->next;
            temp2 = temp2->next;
            temp2->next = NULL;
        }
    }
    node *demo0 = head0;
    node *demo1 = head1;
    node *demo2 = head2;
    head0 = head0->next;
    head1 = head1->next;
    head2 = head2->next;
    delete demo0;
    delete demo1;
    delete demo2;
    temp1->next = head2;
    temp0->next = head1;
    while (head0)
    {
        cout << head0->data << " ";
        head0 = head0->next;
    }
}

int main()
{
    int arr[] = {0, 2, 1};

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