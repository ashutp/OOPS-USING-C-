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

void end(node *head, int x)
{

    if (head->next == NULL)
    {
        node *temp = new node(x);
        temp->next = NULL;
        head->next = temp;
        return;
    }
    end(head->next, x);
}
int main()
{
    int arr[] = {2, 4, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = create(arr, 0, size);
    node *temp = head;
    node *temp2 = head;
    // while (head)
    // {
    //     cout << head->data << " ";
    //     head = head->next;
    // }
    end(temp2, 8);

    while (temp2)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    return 0;
}