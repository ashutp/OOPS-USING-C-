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
node *del(node *pre, node *curr, int pos, int index)
{

    if (pos == 1)
    {
        node *temp = curr;
        if (temp->next == NULL)
        {
            delete temp;
            curr = pre;
            return curr;
        }
        curr = temp->next;
        delete temp;
        return curr;
    }

    if (pos == index)
    {
        if (curr->next == NULL)
        {
            pre->next = NULL;
            return nullptr;
        }
        pre->next = curr->next;
        delete curr;
        return NULL;
    }

    del(curr, curr->next, pos, index + 1);
    return curr;
}

int main()
{
    int arr[] = {2, 4, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = create(arr, 0, size);
    node *temp = head;
    // while (head)
    // {
    //     cout << head->data << " ";
    //     head = head->next;
    // }
    head = del(NULL, head, 3, 1);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}