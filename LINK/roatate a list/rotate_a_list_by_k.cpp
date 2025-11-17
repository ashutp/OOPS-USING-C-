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

node *rotate(node *curr, int pos)
{
    if (pos == 0 || curr == NULL || curr->next == NULL)
    {
        return curr;
    }
    node *temp = curr;
    node *newnode = NULL;
    node *pre = NULL;
    node *tail = NULL;
    if (pos == 1)
    {
        newnode = curr->next;
        curr->next = NULL;
    }
    else
    {

        while (pos)
        {
            pre = curr;
            curr = curr->next;
            pos--;
        }
        newnode = curr;
        pre->next = NULL;
    }

    tail = newnode;
    while (tail)
    {
        if (tail->next == NULL)
        {
            tail->next = temp;
            return newnode;
        }
        tail = tail->next;
    }

    return newnode;
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

    int pos = k % size;
    head = rotate(temp,pos);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}