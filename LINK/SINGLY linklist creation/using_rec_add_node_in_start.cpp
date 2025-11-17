#include <iostream>
#include <vector>
using namespace std;
// there are two methods  start node creation at the end of the array using recursion . add node at the end.
// the second method is raw mehtod .
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
node *nodestart(int arr[], int index, int size, node *prev)
{
    if (index == size)
    {
        return prev;
    }

    node *temp = new node(arr[index]);
    temp->ptr = prev;
    return nodestart(arr, index + 1, size, temp);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = nodestart(arr, 0, size, NULL);

    while (head)
    {
        cout << head->data << " ";
        head = head->ptr;
    }

    return 0;
}