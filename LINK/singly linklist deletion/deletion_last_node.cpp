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
int main()
{
    int x = 0;
    node *head = nullptr;
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
    node *curr = nullptr;
    node *pre = nullptr;

    if (head->next == nullptr)
    {
        node *temp = head;
        head = nullptr;
        delete temp;
    }
    else
    {
        curr = head;
        while (curr->next != nullptr)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        delete curr;
    }
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}