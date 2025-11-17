#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // to write in  a file
    ofstream fout;
    fout.open("demo.txt");
    if (!fout.is_open())
    {
        cout << "not open successfully. " << endl;
    }

    fout << "I am enterd in file " << endl;
    fout.close();

    // to read in a file
    string line;
    ifstream fin;
    fin.open("demo.txt");
    if (!fin.is_open())
    {
        cout << "not open successfully. " << endl;
    }
    while (getline(fin, line))
    {
        cout << line;
    }
    fin.close();
    return 0;
}