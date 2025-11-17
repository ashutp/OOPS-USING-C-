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
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = create(arr, 0, size);
    // int count = 0;
    node *slow = head;
    node *fast = slow;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
        // count++;
    }

    cout << endl;
    while (fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    cout << slow->data;
    return 0;
}