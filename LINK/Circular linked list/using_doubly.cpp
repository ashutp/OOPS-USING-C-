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

node *create(node *curr, int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }

    node *temp = new node(arr[index]);
    temp->pre = curr;
    temp->next = create(temp, arr, index + 1, size);
    return temp;
}
int main()
{
    int arr[] = {1};
    int size = sizeof(arr) / sizeof(arr[0]);

    node *head = create(NULL, arr, 0, size);
    node *tail = NULL;
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        tail = temp;
        temp = temp->next;
    }
    tail->next = head;
    head->pre = tail;
    // while (tail)
    // {
    //     cout << tail->data << endl;
    //     tail = tail->next;
    // }

    return 0;
}