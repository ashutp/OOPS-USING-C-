#include <iostream>
#include <vector>
using namespace std;
// hybrid inheritance means there are make with the help mulitple types of class
class male
{
protected:
    string gender = "male";
    int age;

public:
};
class stu
{
protected:
    string name;
    int roll_no, fee;

public:
};
class female
{
protected:
    string gender = "female";
    int age;

public:
};

class boy : public male, public stu
{
public:
    boy()
    {
        cout << "deaful destructor call" << endl;
    }
    boy(string nam, int ag, int rol, int fe)
    {
        this->name = nam;
        this->age = ag;
        this->roll_no = rol;
        this->fee = fe;
    }
    void display()
    {
        cout << name << " " << age << " " << roll_no << " " << fee << " " << gender << endl;
    }
};

class girl : public female, public stu
{
public:
    girl()
    {
        cout << "deaful destructor call" << endl;
    }
    girl(string nam, int ag, int rol, int fe)
    {
        this->name = nam;
        this->age = ag;
        this->roll_no = rol;
        this->fee = fe;
    }
    void display()
    {
        cout << name << " " << age << " " << roll_no << " " << fee << " " << gender << endl;
    }
};
int main()
{
    boy obj("ashu", 21, 29, 2000);
    obj.display();
    girl obj1("monika", 16, 5, 900);
    obj1.display();

    return 0;
}