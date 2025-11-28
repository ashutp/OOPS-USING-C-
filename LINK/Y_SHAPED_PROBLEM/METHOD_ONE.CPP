#include <iostream>
#include <vector>
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
    int arr2[] = {8, 9};
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
    temp = head;
    temp2 = head2;

    int count1 = 0;
    int count2 = 0;

    while (temp)
    {
        // cout << temp->data << " ";
        temp = temp->next;
        count1++;
    }
    // cout << endl;
    while (temp2)
    {
        // cout << temp2->data << " ";
        temp2 = temp2->next;
        count2++;
    }
    // cout << endl;

    // cout << count1 << " " << count2;

    int c = count1 - count2;
    while (c)
    {
        head = head->next;
        c--;
    }

    while (head != NULL && head2 != NULL)
    {
        if (head2 == head)
        {
            cout << "Meet here :" << head2 << " = " << head << endl;

            return 0;
        }

        head = head->next;
        head2 = head2->next;
    }

    return 0;
}