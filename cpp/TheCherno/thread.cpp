#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void oneFunction()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "one Function" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void twoFunction()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "two Function" << endl;
        this_thread::sleep_for(chrono::milliseconds(70));
    }
}

int main()
{
    thread one(oneFunction);
    thread two(twoFunction);

    one.join();
    two.join();
    return 0;
}