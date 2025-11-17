#include <iostream>
#include <vector>
using namespace std;
class con
{
private:
public:
    string name;
    int *age;

    con()
    {
        cout << "default constructor\n";
    }
    con(string name, int age)
    {
        this->name = name;
        this->age = &age;
    }
    con(con &obj)
    {
        this->name = obj.name;
        this->age = new int;
        this->age = obj.age;
    }
    void set(int a)
    {
        this->age = new int;
        *age = a;
    }
    void display()
    {
        cout << this->name << " " << *age << endl;
    }
};

int main()
{
    int ag = 13;
    con obj("ashu", 12);
    con obj2(obj);
    obj2.set(ag);
    obj.display();
    obj2.display();
    return 0;
}