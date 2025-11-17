#include <iostream>
#include <vector>
using namespace std;
class demo
{
    static int a;
    // int b;
public:
    static int fun()
    {
        a++;
        cout << a << endl;
    }
};
int demo::a = 0;
int main()
{
    demo ::fun();
    demo obj;
    obj.fun();
    return 0;
}