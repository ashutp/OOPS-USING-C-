#include <iostream>
#include <vector>
using namespace std;
class con
{

private:
    int *ptr;
    string name;

public:
    con()
    {
        cout << "Default constructor :" << endl;
    }

    con(string name, int age)
    {
        this->ptr = &age;
        this->name = name;
        cout << ptr << endl;
    }
    con(con &&obj)
    {
        this->ptr = obj.ptr;
        obj.ptr = nullptr;
        cout << this->ptr << " " << obj.ptr;
    }
};
int main()
{
    con obj("ashu", 12);
    con obj2 = move(obj);

    return 0;
}