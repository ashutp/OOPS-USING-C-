#include <iostream>
#include <vector>
using namespace std;
class node
{

public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

node *fun(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }

    node *temp = new node(arr[index]);
    temp->next = fun(arr, index + 1, size);
    return temp;
}

int main()
{
    int arr[] = {1, 2, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;

    head = fun(arr, 0, size);
    node *head2 = head;
    vector<int> str;
    str.push_back(head->data);
    while (head)
    {
        if (str[str.size() - 1] != head->data)
        {
            str.push_back(head->data);
        }
        head = head->next;
    }
    // for (int i = 0; i < str.size(); i++)
    // {
    //     cout << str[i] << " ";
    // }
    int count = 0;
    head = NULL;
    head = head2;
    while (count < str.size())
    {
        head2->data = str[count];
        if (count + 1 == str.size())
        {
            head2->next = NULL;
            break;
        }
        head2 = head2->next;
        count++;
    }
    head2->next = NULL;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}