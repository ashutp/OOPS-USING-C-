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

node *merge(node *head1, node *head2)
{

    node *head3 = new node(0);
    node *temp = head3;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            temp->next = new node(head1->data);
            head1 = head1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = new node(head2->data);
            head2 = head2->next;
            temp = temp->next;
        }
    }
    if (head1 != NULL)
    {
        temp->next = head1;
    }
    else if (head2 != NULL)
    {
        temp->next = head2;
    }
    node *temp2 = head3;
    head3 = head3->next;
    delete temp2;
    return head3;
}
int main()
{
    int arr[] = {1, 2, 2, 4, 4};
    int arr2[] = {1, 3, 3, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr[0]);

    node *head = NULL;
    node *head2 = NULL;
    head2 = fun(arr2, 0, size);
    head = fun(arr, 0, size2);
    node *head3 = merge(head, head2);
    while (head3)
    {
        cout << head3->data << " ";
        head3 = head3->next;
    }

    return 0;
}