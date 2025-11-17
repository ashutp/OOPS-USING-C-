#include <iostream>
#include <vector>
using namespace std;
class des
{
    int ex;

public:
    des()
    {

        cout << " constructor" << endl;
    }

    des(int a)
    {
        ex = a;
        cout << ex << " constructor" << endl;
    }

    ~des()
    {
        cout << ex << " destruction" << endl;
    }
};

int main()
{
    des obj(1);
    des obj1(2);
    des *obj3 = new des(3);
    des obj2(4);
    delete obj3;
    return 0;
}