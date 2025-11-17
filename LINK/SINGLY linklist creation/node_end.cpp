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
    node *head = NULL;
    int arr[] = {1, 2, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        if (head == NULL)
        {
            head = new node(arr[i]);
        }
        else
        {
            node *tail;
            tail = head;
            while (tail->ptr)
            {
                tail = tail->ptr;
            }
            tail->ptr = new node(arr[i]);
            // cout<<" fuck";
        }
    }
    while (head)
    {
        cout << head->data << " ";
        head = head->ptr;
    }

    return 0;
}