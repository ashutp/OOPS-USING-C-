#include <iostream>
#include <vector>
using namespace std;
// the topic is compile time polymorphism  : function overloading and operator overlaoding this will happen's in compile time . they are also called as early binding .
class demo
{
    int real;
    int image;

public:
    // when we working with same name function but deferant argumants number they are called function overloading the early binding compiler bind in compile time.
    // you also use deffernt datatype function with same name
    //  { this are function overloading examples .
    demo()
    {
        cout << "deafult constructor\n";
    }
    demo(int real, int image)
    {
        this->real = real;
        this->image = image;
    }
    int area(int x)
    {
        return (3.14 * x * x);
    }
    int area(int l, int b)
    {
        return l * b;
    }
    string area(string s)
    {
        return s;
    }
    // }

    // { operator overlading :💡 1️⃣ Not all operators can be overloaded
    // You can overload most C++ operators (like +, -, ==, [], ()),
    // ⚙️ 2️⃣ At least one operand must be a user-defined type
    // You can’t overload an operator for only primitive types.
    // 🧱 3️⃣ Overloaded operators don’t change precedence or associativity
    // Even after overloading,
    // 🧠 4️⃣ Prefer member functions for modifying the left operand; use friend functions for symmetry
    // 5️⃣ Return by value (not by reference) for arithmetic operators

    demo operator+(demo &c)
    {
        demo ans;
        ans.real = this->real + c.real;
        ans.image = this->image + c.image;
        return ans;
    }

    void display()
    {
        cout << this->real << " " << this->image << endl;
        }
};
int main()
{
    demo obj;
    cout << obj.area("ashu") << endl;
    cout << obj.area(3) << endl;
    cout << obj.area(3, 5)<<endl;
    demo obj1(10, 20);
    demo obj2(20, 70);
    demo obj3 = obj1 + obj2;
     obj3.display();
    return 0;
}