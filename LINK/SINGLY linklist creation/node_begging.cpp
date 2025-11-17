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
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head;
    head = NULL;
    for (int i = 0; i < size; i++)
    {
        if (head == NULL)
        {
            head = new node(arr[i]);
        }
        else
        {
            node *temp;
            temp = new node(arr[i]);
            temp->ptr = head;
            head = temp;
        }
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->ptr;
    }

    return 0;
}