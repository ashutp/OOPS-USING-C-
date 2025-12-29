#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    // using stl we can crate a stack data structure
    // C++ provides a ready-made stack implementation in the STL.
    
    stack<int> S;

    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    cout << S.top() << endl;
    cout << S.empty() << endl;
    cout << S.size() << endl;
    // they have some methods

    return 0;
}