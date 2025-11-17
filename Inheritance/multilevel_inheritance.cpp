#include <iostream>
#include <vector>
using namespace std;
// When you create an object of C:
// Memory contains data for A, B, and C.
// Constructor order (from top to bottom):
// A() → B() → C()
// Destructor order (reverse):
// ~C() → ~B() → ~A()
// So, base to derived while constructing,
// and derived to base while destroying.
class human
{
protected:
    int age;
    string name;

public:
    human()
    {
        cout << "Human constructor runs\n";
    }
};
class teacher : public human
{
protected:
    int id;
    string subject;

public:
    teacher()
    {
        cout << "teacher constructor runs\n";
    }
};
class student : public teacher
{
    int roll;
    int fee;

public:
    student()
    {
        cout << "student constructor runs\n";
    }
    student(string name, int age, int fee, int roll, string subject)
    {
        this->name = name;
        this->age = age;
        this->fee = fee;
        this->roll = roll;
        this->subject = subject;
        cout << "student constructor user defined constructoe runs\n";
    }
    void disply()
    {
        cout << this->name << " " << this->age << " " << this->fee << " " << this->roll << " " << this->subject << " " << endl;
    }
};

int main()
{
    student obj("ashu", 21, 19000, 18, "maths");
    obj.disply();
    return 0;
}