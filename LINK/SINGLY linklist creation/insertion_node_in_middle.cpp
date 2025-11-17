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
node *createlist(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }
    node *temp = new node(arr[index]);
    temp->ptr = createlist(arr, index + 1, size);
    return temp;
}
int insertion(node *list, int target, int value)
{
    while (list)
    {
        if (list->data == target)
        {
            node *temp = new node(value);
            temp->ptr = list->ptr;
            list->ptr = temp;
            return 0;
        }
        list = list->ptr;
    }
    return 0;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = createlist(arr, 0, size);
    insertion(head, 5, 6);
    while (head)
    {
        cout << head->data << " ";
        head = head->ptr;
    }

    return 0;
}