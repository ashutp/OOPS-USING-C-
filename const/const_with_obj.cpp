#include <iostream>
#include <vector>
using namespace std;
// ⚙️ 2. Const Data Member
// A const data member means its value cannot change after initialization.
// void fun()const{}
// This function will not modify any data members of the class.
// A const object of a class means:
// You can only call const member functions on it.

// demo() : a(10) {}.
// demo(int val) : a(val) {} using intilizer list.
// if you use const value in your class . use this  constructor syntax for deafault constructor because const value intilizes when the obj is create.
class demo
{
    const int a;

public:
    demo() : a(10) {}

    void display() const
    {

        cout << a;
    }
    void set()
    {
        cout << a;
    }
};
int main()
{
    const demo obj;
    obj.display();
    // obj.set();
    return 0;
}