#include <iostream>
#include <vector>
using namespace std;

// timeComplexcity O(1)
// space complexcity O(1);

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
    node *loc = head;
    cout << "Before deletion result: " << endl;
    while (loc)
    {
        cout << loc->data << " ";
        loc = loc->next;
    }

    if (head->next == nullptr)
    {
        node *temp = head;
        head = nullptr;
        delete temp;
    }
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nAfter deletion result: " << endl;

    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}