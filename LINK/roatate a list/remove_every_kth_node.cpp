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

node *remove(node *curr, int k, int index)
{
    node *head = curr;
    node *pre = NULL;

    while (curr)
    {
        if (k == index)
        {
            node *temp = curr;
            pre->next = curr->next;
            delete temp;
            curr = pre->next;
            index = 0;
        }
        else
        {

            pre = curr;
            curr = curr->next;
        }
        index++;
    }

    return head;
}
int main()
{
    int arr[] = {2, 4, 6, 8, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = create(arr, 0, size);
    node *temp2 = head;

    node *temp = remove(head, 2, 1);

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}