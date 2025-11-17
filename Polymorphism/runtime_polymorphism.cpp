#include <iostream>
#include <vector>
using namespace std;
// what is runtime polymorphism
// Run time polymorphism means there fun() binding in run tme not compile time they are actualy help in
// when base class have same name fun() and derived class have the same function.when you create base
// class pointer and give child class obj address  to store child class obj when you access child class.
// display() property without using virtual keyword you don't access. you acces base class display fun()
// not derived class .when you useing virtual keyword they denote the function binding can be happen in
// runtime and the called function not depand on on pointer they depend on the obj that address pointer store.


class base
{
public:
    virtual void display()
    {
        cout << "i am base class\n";
    }
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