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

node *add_anywhere(node *head, int pos,int  size)
{

    node *temp = new node(100);
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return head;
    }
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
        temp->next = curr;
        pre->next = temp;
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

    head = add_anywhere(head, 10,10);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}