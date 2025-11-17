#include <iostream>
#include <vector>
#include <unordered_map>

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
    // loop created here
    while (temp)
    {
        cout << temp->data << " ";
        tail = temp;
        temp = temp->ptr;
    }
    tail->ptr = head;
    tail = tail->ptr;

    // finding  loop using fast and slow pointer
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->ptr != NULL)
    {
        
        slow = slow->ptr;
        fast = fast->ptr->ptr;
        if (fast == slow)
        {
            cout << "loop:";
            return 0;
        }
    }
    cout << "loop was not present";

    return 0;
}