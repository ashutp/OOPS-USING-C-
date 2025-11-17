#include <iostream>
#include <vector>
using namespace std;
// single inheritance means they are only one base calss and one derived class
// When you create Derived obj;
// Memory is allocated for both the Base part and the Derived part.
// The Base constructor runs first.
// Then the Derived constructor runs.
// When object is destroyed:
// Derived destructor runs first.
// // Then Base destructor runs
class base
{

public:
    base()
    {
        cout << "base constructor called\n";
    }
    virtual void display()
    {
        cout << "base class method\n";
    }
};
class derived : public base
{
public:
    derived()
    {
        cout << "derived constructor called\n";
    }
    void display()
    {
        cout << "derived  class method\n";
    }
};
int main()
{
   base obj;
    // here when you use display method here base and derived class both of them contain display() menmber function so compiler first check called method in the object itself  .when they not find they search in parent class.
  obj.display();
 

    return 0;
}