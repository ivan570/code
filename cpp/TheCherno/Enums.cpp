#include <iostream>
using namespace std;

enum student : unsigned long long int // inherited value must be the interger type data type liked int, char, short, long
// double and float will not allow
{
	roll_no = 234444444423, age = 90527410255
};

int main() {

	cout << roll_no << " " << age;
	return 0;
}