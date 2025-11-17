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

node *del(node *head, int pos)
{
    if (pos == 1)
    {
        node *temp = head;
        if (head->next == NULL)
        {
            delete temp;
            head = NULL;
            return head;
        }
        else
        {
            head = head->next;
            delete temp;
        }
    }
    else
    {
        pos--;
        node *pre = NULL;
        node *curr = head;
        while (pos)
        {
            pre = curr;
            curr = curr->next;
            pos--;
        }
        node *ptr = curr;
        pre->next = curr->next;
        curr = nullptr;
        delete ptr;
    }

    return head;
}

int main()
{
    int x = 0;
    node *head = NULL;
    node *temp = new node(x);
    x++;
    head = temp;
    while (x != 10)
    {
        node *temp2 = new node(x);
        temp->next = temp2;
        temp = temp->next;
        x++;
    }

    head = del(head, 1);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}