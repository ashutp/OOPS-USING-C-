#include <iostream>
#include <vector>
using namespace std;
// there are famouse problem in multi path inheritance called was diamond problem
// So the inheritance path forms a diamond shape ⬇️
//         A
//        / \
//       B   C
//        \ /
//         D
// A → Base class
// B and C → Derived from A
// D → Derived from both B and C
// when we create this types of inheritance structure we can face ambiguity because the B and C class both contain same value when the D class use this value. the compiler confuse which one to use in D class.
// to resolve this problem we can use virtual keyword

class human
{
protected:
    int Age;
    string name;
    string gender;

public:
    human()
    {
        cout << "Human construcotr called" << endl;
    }
};
class boy : virtual public human
{
protected:
    // string gender = "boy";

public:
    boy()
    {
        cout << "boy construcotr called" << endl;
    }
};
class girl : virtual public human
{
protected:
    // string gender = "girl";

public:
    girl()
    {
        cout << "girl construcotr called" << endl;
    }
};
class athelte : public girl, public boy
{
    string game;
    int roll_no;

public:
    athelte()
    {
        cout << "athelte constructor called" << endl;
    }
    athelte(string nam, string gen, int age, int roll, string gam)
    {
        name = nam;
        gender = gen;
        Age = age;
        roll_no = roll;
        game = gam;
        cout << "athelte constructor called" << endl;
    }
    void display()
    {
        cout << name << " " << gender << " " << Age << " " << roll_no << " " << game << endl;

    }
};
int main()
{
    athelte obj("ashu", "male", 21, 12, "cricket");
    obj.display();
    return 0;
}