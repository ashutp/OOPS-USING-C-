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

int palindrome(node *curr, int size)
{
    if (curr->next == NULL)
    {
        return 1;
    }

    int pos = size / 2;
    node *temp = curr;
    node *pre = NULL;
    while (pos)
    {
        pre = temp;
        temp = temp->next;
        pos--;
    }
    pre->next = NULL;
    node *prelist = curr;
    node *newlist = temp;
    node *fut = NULL;
    curr = newlist;
    pre = NULL;
    while (curr)
    {
        fut = curr->next;
        curr->next = pre;
        pre = curr;
        curr = fut;
    }
    newlist = pre;
    while (prelist)
    {

        if (prelist->data != newlist->data)
        {
            return 0;
        }
        prelist = prelist->next;
        newlist = newlist->next;
    }
    return 1;
}
int main()
{
    int arr[] = {1, 2, 3, 0, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = create(arr, 0, size);
    node *temp2 = head;

    // while (temp2)
    // {
    //     cout << temp2->data << " ";
    //     temp2 = temp2->next;
    // }
    if (palindrome(head, size))
    {
        cout << " haa";
    }
    else
    {
        cout << "na";
    }

    return 0;
}