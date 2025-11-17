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

node *remove_node(node *pre, node *curr, int index, int pos)
{
    if (index == 0 && curr->next == NULL)
    {
        delete curr;
        return NULL;
    }

    if (pos == 0)
    {
        node *temp = curr;
        curr = curr->next;
        delete temp;
        return curr;
    }
    if (pos == index)
    {

        pre->next = curr->next;
        delete curr;
        return NULL;
    }

    remove_node(curr, curr->next, index + 1, pos);

    return curr;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = create(arr, 0, size);
    node *temp = head;
    // while (head)
    // {
    //     cout << head->data << " ";
    //     head = head->next;
    // }

    int k;
    cout << "Enter the kth positon :";
    cin >> k;
    head = remove_node(NULL, head, 0, size - k);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}