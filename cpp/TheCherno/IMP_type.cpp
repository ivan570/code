#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	std::cout << "Enter number is(int) ==> " << n << "\n";

	std::cout << "double process start\n";

	double d_n = *(double*)&n; // error
	std::cout << "Enter number is(double) ==> " << d_n << "\n";

	int data = 90;
	int* pointer = &data;
	std::cout << pointer[0] << std::endl;

	std::cin.get();
	return 0;
}