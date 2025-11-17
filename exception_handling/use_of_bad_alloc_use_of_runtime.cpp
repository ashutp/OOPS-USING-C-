#include <iostream>
#include <vector>
#include <exception>
using namespace std;
// the exception is a base class  and runtime and bad_alloc is derived form base class.
// this derived class's inheriate base class method when you crate drived class obj
// derived class constructor call and pass value to base class.
// using this obj you can acces the value.

#include <iostream>
#include <stdexcept>
#include <new>
#include <exception>
using namespace std;

int main() {
    try {
        cout << "1️⃣ Trying to allocate huge memory..." << endl;
        int* bigArray = new int[100000000000000];  // 1 billion ints

        // Force the OS to really allocate the memory
        for (long long i = 0; i < 1000000000; i++) {
            bigArray[i] = i;  // touch each memory cell
        }

        cout << "2️⃣ Now performing division..." << endl;
        int a = 10, b = 0;
        if (b == 0)
            throw runtime_error("Division by zero!");

        cout << "Result: " << a / b << endl;

        delete[] bigArray;
    }
    catch (const bad_alloc &e) {
        cout << "❌ Memory allocation failed: " << e.what() << endl;
    }
    catch (const runtime_error &e) {
        cout << "⚠️ Runtime error: " << e.what() << endl;
    }
    catch (const exception &e) {
        cout << "Other exception: " << e.what() << endl;
    }

    cout << "✅ Program ended safely." << endl;
    return 0;
}
