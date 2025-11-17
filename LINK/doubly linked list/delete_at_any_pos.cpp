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

node *create(int arr[], int size)
{

    node *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++)
    {
        if (head == NULL)
        {
            head = new node(arr[i]);
            tail = head;
        }
        else
        {
            node *temp = new node(arr[i]);
            temp->pre = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

node *delany(node *curr, int pos)
{
    node *ptr = curr;
    if (curr == NULL)
    {
        cout << "Head is empty :";
        return curr;
    }
    else if (pos == 1)
    {
        if (curr->next == NULL)
        {
            delete curr;
            curr = NULL;
            return curr;
        }
        else
        {
            node *temp = curr;
            curr = curr->next;
            curr->pre = NULL;
            delete temp;
            return curr;
        }
    }
    else
    {

        while (--pos)
        {
            curr = curr->next;
        }
        if (curr->next == NULL)
        {
            node *temp = curr;
            curr->pre->next = NULL;
            delete temp;
            return ptr;
        }
        else
        {

            node *temp = curr;
            curr->pre->next = curr->next;
            delete temp;
            return ptr;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = create(arr, size);
    head = delany(head, 5);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}