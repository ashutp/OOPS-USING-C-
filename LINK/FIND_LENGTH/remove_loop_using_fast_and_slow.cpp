#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class node
{

public:
    int data;
    node *ptr;
    node(int value)
    {
        data = value;
        ptr = NULL;
    }
};

node *fun(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }

    node *temp = new node(arr[index]);
    temp->ptr = fun(arr, index + 1, size);
    return temp;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = fun(arr, 0, size);
    // for node createing purpose
    node *create = head->ptr->ptr;
    node *temp = head;
    while (temp)
    {
        if (temp->ptr == NULL)
        {
            temp->ptr = create;
            break;
        }

        temp = temp->ptr;
    }

    node *slow = head;
    node *fast = head;
    bool check = false;
    while (fast != NULL && fast->ptr != NULL)
    {
        fast = fast->ptr->ptr;
        slow = slow->ptr;
        if (fast == slow)
        {
            check = true;
            break;
        }
    }

    if (check)
    {
        cout << "Loop is present" << endl;
        slow = head;
        while (slow != fast)
        {
            slow = slow->ptr;
            fast = fast->ptr;
        }
        
       
        while (slow->ptr != fast)
        {
            // cout << slow->data << " " ;
            slow = slow->ptr;
        }

        slow->ptr = NULL;
    }
    else
    {
        cout << "Loop not present" << endl;
    }
cout<<endl;
    while (head)
    {
        cout << head->data << " ";
        head = head->ptr;
    }

    return 0;
}