#include <iostream>
#include <vector>
using namespace std;
class human
{
protected:
    string gender;
    string name;

public:
   human()
   {
       cout << "deafault constructor huamn " << endl;
   }
};

class stu : public human
{
    int roll_no;
    int age;

public:
    stu()
    {
        cout << "\ndeafault constructor student" << endl;
    }
    stu(string nam, string gen, int roll, int Age)
    {
        name = nam;
        gender = gen;
        roll_no = roll;
        age = Age;
     
    }
    void display()
    {
        cout << name << " " << age << " " << roll_no << " " << gender<<endl;
    }
};
class teach : public human
{
    int id;
    int age;

public:
    teach()
    {
        cout << "\ndeafault constructor teacher" << endl;
    }
    teach(string nam, string gen, int Id, int Age)
    {
        name = nam;
        gender = gen;
        id = Id;
        age = Age;
    }
    void display()
    {
        cout << name << " " << age << " " << id << " " << gender<<endl;
    }
};
int main()
{
stu obj("ashu","male",21,18);
obj.display();
teach obj2("himanshu","male",20,19);
obj2.display();
    return 0;
}