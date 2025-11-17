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

node *reverse(node *curr, node *pre)
{
    if (curr == NULL)
    {
        curr = pre;
        return curr;
    }
    node *fut = curr->next;
    curr->next = pre;
    return reverse(fut, curr);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = create(arr, 0, size);
    head = reverse(head, NULL);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}