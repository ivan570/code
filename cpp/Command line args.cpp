#include <iostream>
using namespace std;

int main(int argc, char const *str_argv[])
{
	for (int i = 0; i < argc; ++i)
		cout << str_argv[i] << endl;
	return 0;
}