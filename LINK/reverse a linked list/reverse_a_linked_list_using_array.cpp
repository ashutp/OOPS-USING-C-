#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node() {

    };
    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

node *create(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }

    node *temp = new node(arr[index]);
    temp->next = create(arr, index + 1, size);
    return temp;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = create(arr, 0, size);

    // while (head)
    // {
    //     cout << head->data << " ";
    //     head = head->next;
    // }

    node *head2 = head;
    node *temp = head;
    int arr2[5];
    int index = 0;
    while (head2)
    {
        arr2[index] = head2->data;
        head2 = head2->next;
        index++;
    }
    for (int i = 4; i >= 0; i--)
    {
        temp->data = arr2[i];
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}