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

node *insert(node *head, int pos, int ele)
{


    node *ptr=head;
    if (pos == 0)
    {
        node *temp = new node(ele);
        temp->next = head;
        head->pre = temp;
        head = temp;
        return head;
    }
    else
    {
        while (--pos)
        {
            head = head->next;
        }
        if (head->next == NULL)
        {
            node *temp = new node(ele);
            head->next = temp;
            temp->pre = head;
        }
        else
        {
            node *temp = new node(ele);
            temp->next = head->next;
            temp->pre = head;
            head->next = temp;
            temp->next->pre = temp;
        }
    }
    return ptr;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = create(arr, size);
    head=insert(head,1,0);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}