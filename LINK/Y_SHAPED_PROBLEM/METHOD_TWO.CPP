#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node(int value)
    {
        data = value;
    }
};

Node *create(Node *head, int arr[], int size, int index)
{
    if (size == index)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);

    temp->next = create(temp, arr, size, index + 1);
    return temp;
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head = NULL;
    head = create(head, arr, size, 0);
    Node *head2 = NULL;
    head2 = create(head2, arr2, size2, 0);

    Node *temp = head;
    Node *temp2 = head2;

    while (temp->data != 5)
    {
        temp = temp->next;
    }
    while (temp2)
    {
        if (temp2->next == NULL)
        {
            temp2->next = temp;
            break;
        }
        
        temp2 = temp2->next;
    }
    unordered_map<Node *, bool> visited;
    temp = head;
    temp2 = head2;
    while (temp)
    {
        visited[temp] = 1;
        temp = temp->next;
    }
    while (temp2)
    {
       
        if (visited[temp2])
        {
            cout << "Meet here : " << temp2->data << endl;
            return 0;
        }
        temp2 = temp2->next;
    }

    return 0;
}