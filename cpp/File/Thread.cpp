#include <iostream>
#include <thread>
using namespace std;

void functionForThread()
{
    static long long sum = 0;
    for (long long int i = 0; i < 900000000; ++i)
    {
        sum += i;
        sum %= (90000000 * 2);
    }
    cout << sum << endl;
}
int main()
{
    time_t start, end;
    time(&start);
    thread th2(functionForThread);
    thread th1(functionForThread);

    th1.join();
    th2.join();
    time(&end);
    cout << double(end - start);
    return 0;
}
