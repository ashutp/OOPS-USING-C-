#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *pre = NULL;
    node *next = NULL;
    node(int x)
    {
        data = x;
    }
};

node *create(node *head, int arr[], int index, int size)
{
    if (index == size)
    {
        return head;
    }

    if (head == NULL)
    {
        head = new node(arr[index]);
    }
    else
    {
        node *temp = new node(arr[index]);
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    return create(head, arr, index + 1, size);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    node *head = create(NULL, arr, 0, size);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}