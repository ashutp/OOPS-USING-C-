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
    int length = size - k;
    node *pre = NULL;
    while (length)
    {
        pre = temp;
        temp = temp->next;
        length--;
    }
    pre->next = NULL;
    pre = temp;
    while (temp)
    {
        if (temp->next == NULL)
        {
            temp->next = head;
            break;
        }
        temp = temp->next;
    }

    while (pre)
    {
        cout << pre->data << endl;
        pre = pre->next;
    }
    return 0;
}