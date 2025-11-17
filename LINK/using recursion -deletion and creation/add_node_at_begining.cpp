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

node *add_begining(node *head, int index, int size)
{
    if (index == size)
    {
        return head;
    }
    node *temp = new node(123);
    temp->next = head;

    return add_begining(temp, index + 1, size);
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
    head = add_begining(head, 0, 1);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}