#include <iostream>
using namespace std;

class Base
{
public:
    void show()
    {
        cout << "Base class show" << endl;
    }
};

class Derive : public Base
{
public:
    // it's also polymorphism
    // it's function overriding
    int show()
    {
        cout << "Derive class show" << endl;
        return 23;
    }
};

void function(int first, int second)
{
    cout << "x is " << first << " y is " << second << endl;
}

void function(int first, int second, int third)
{
    cout << "first is " << first << " second " << second << " third " << third << endl;
}

int main()
{
    Derive derive;
    derive.show();
    // function overloading
    function(90, 99);
    function(89, 90);
    return 0;
}
