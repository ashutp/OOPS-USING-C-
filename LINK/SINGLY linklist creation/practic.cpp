#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *ptr;
    void display()
    {
        cout << data << " " << ptr << endl;
    }
};
int main()
{
    node *ptr = new node;
    ptr->data = 5;
    ptr->ptr = NULL;
    ptr->display();
    return 0;
}