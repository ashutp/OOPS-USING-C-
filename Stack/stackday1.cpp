#include <iostream>
#include <vector>
#include <exception>
using namespace std;
class stack
{
private:
    int data[5];
    int top;

public:
    stack()
    {
        top = -1;
        cout << "Stack was created\n";
    }
    void push(int val)
    {
        if (top == 4)
        {
            throw string("error: stack overflow :\n");
        }
        else
        {
            top++;
            data[top] = val;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            throw string("error: stack underflow :\n");
        }
        top--;
    }
    void peek()
    {
        if (top == -1)
        {
            throw string("error : no data present in stack\n");
        }
        else
        {
            cout << "peek element was :"
                 << data[top] << endl;
        }
    }
    void iSsize()
    {
      cout<<"Size of stack was: "<<top+1<<endl;
    }

    int isempty()
    {
        if (top == -1)
        {

            return top;
        }
        else
        {
            return 1;
        }
    }
}

;
int main()
{
    stack obj;
    try
    {
        /* code */

        obj.push(1);
        // obj.pop(); obj.pop();
        obj.push(1);
        obj.push(1);
        obj.push(1);
        obj.push(1);
        obj.push(1);


        // obj.pop();
        // obj.peek();
        obj.iSsize();

        cout << obj.isempty();
    }
    catch (const string e)
    {
        cout << e << '\n';
    }
}