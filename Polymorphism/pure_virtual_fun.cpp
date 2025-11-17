#include <iostream>
#include <vector>
using namespace std;
// pure virtual fun() means they belongs to abstract class they cant create own obj beacause they have no
// defination of function /fun() have no body if you try to create obj of pure function you got error.
// A class that contains at least one pure virtual function becomes an abstract class.
//  they only used to access derived class fun() using base class .

class base
{
public:
    virtual void display() = 0;
};
class derived : public base
{
public:
    void display()
    {
        cout << "i am dervid class\n";
    }
};
int main()
{
    base *ptr = new derived();
    ptr->display();

    return 0;
}