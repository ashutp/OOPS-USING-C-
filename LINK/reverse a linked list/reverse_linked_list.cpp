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

// logic behind it : was when you reversing a node you take three pointer.
// pre ,curr,futur,: pre take previouse node address,and curr take current node address and fut stores future node address.
// futur store currenet next-> address,and curr->next previous address, and last previous store curr node address.

node *reverse(node *curr)
{
    node *pre = NULL, *fut;
    while (curr)
    {
        fut = curr->next;
        curr->next = pre;
        pre = curr;
        curr = fut;
    }
    return pre;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = create(arr, 0, size);

    node *temp = head;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    temp = reverse(temp);
    cout << endl;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}