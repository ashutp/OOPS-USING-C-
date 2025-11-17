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

node *create(int arr[], int size)
{

    node *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++)
    {
        if (head == NULL)
        {
            head = new node(arr[i]);
            tail = head;
        }
        else
        {
            node *temp = new node(arr[i]);
            temp->pre = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = create(arr, size);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}