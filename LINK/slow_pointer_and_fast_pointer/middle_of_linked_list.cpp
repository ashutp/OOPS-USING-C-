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
    int count = 0;
    node *temp = head;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
        count++;
    }

    count /= 2;
    cout<< endl;
    while (count)
    {
        temp = temp->next;
        count--;
    }
    cout<<temp->data;

    return 0;
}