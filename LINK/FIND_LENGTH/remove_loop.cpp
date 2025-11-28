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
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = NULL;
    head = fun(arr, 0, size);
    node *tail = NULL;
    node *temp = head;
    node *head2 = head;
    // loop created here
    while (temp)
    {
        cout << temp->data << " ";
        tail = temp;
        temp = temp->ptr;
    }
    tail->ptr = head;
    tail = tail->ptr;

    // loop
    unordered_map<node *, bool> visited;
    node *check = NULL;
    while (tail)
    {
        if (visited[tail] == 1)
        {
            cout << "loop is present in linked list " << endl;
            check = tail;
            int count = 0;
            while (tail)
            {
                count++;
                if (tail->ptr->ptr == check)
                {
                    count++;
                    cout << "length of the loop " << count << endl;
                    tail->ptr->ptr = NULL;
                    // return 0;
                    break;
                }
                // visited[tail] = 1;
                tail = tail->ptr;
            }

            // return 0;
            break;
        }
        visited[tail] = 1;
        tail = tail->ptr;
    }

    while (head2)
    {
        cout << head2->data << " ";
        head2 = head2->ptr;
    }

    return 0;
}