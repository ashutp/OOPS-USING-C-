#include <iostream>
#include <vector>
#include <exception>
using namespace std;
// What is an Exception:
// An exception is an unexpected or abnormal event that occurs during the runtime of a program.
// Exception handling is a technique that allows us to handle these runtime errors
// gracefully without crashing the program.
// In C++, all exceptions are derived from the base class 'std::exception'.
// Derived classes like 'std::bad_alloc', 'std::runtime_error', etc. represent specific types of exceptions.
// We can catch exceptions using a reference to the base class 'std::exception' or to a specific derived class.
// Methods
// try	Defines a block of code that might throw an exception
// throw	Used to throw an exception
// catch	Defines a block of code to handl

// to better understanding we create s small banking system
class bank
{
    string name;
    int b_acc;
    int balance;

public:
    bank()
    {
        cout << "Default constructor: " << endl;
    }
    bank(string name, int bacc, int balance)
    {
        this->name = name;
        this->b_acc = bacc;
        this->balance = balance;
    }

    void deposite(int balance)
    {
        if (balance <= 0)
        {
            throw string("Insufficent value:");
        }
        this->balance += balance;
        cout << "Reamaning balance :" << this->balance << endl;
    }
    void withdraw(int balance)
    {
        if (balance <= 0)
        {
            throw string("Insufficent value:");
        }
        this->balance -= balance;
        cout << "Reamaning balance :" << this->balance << endl;
    }
};
int main()
{
    bank acc("ashu", 123, 5000);

    try
    {
        acc.deposite(0);
        acc.withdraw(0);
    }
    catch (const string e)
    {
        cout << e << '\n';
    }

    return 0;
}