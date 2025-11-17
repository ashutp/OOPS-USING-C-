#include <iostream>
#include <vector>
using namespace std;
class base1
{
public:
    void dis()
    {
        cout << "base1" << endl;
    }
};
class base2
{
public:
    void dis()
    {
        cout << "base1" << endl;
    }
};
class derived : public base1, public base2
{
public:
    void dis()
    {
        // ambiguity problem resolution rsolution
        // problem is that if you define both base class fun with same name .when you acces define method compiler confused which one they can use .
        base1::dis();
    }
};
int main()
{
    derived obj;
    obj.dis();

    return 0;
}