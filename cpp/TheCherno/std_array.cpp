#include <iostream>
#include <array>

template <std::size_t size>
void print(std::array<int, size> array) {
	for (int i = 1; i < size; ++i)
		std::cout << array[i] << " ";
	std::cout << "\n";
}

int main()
{
	std::array<int, 3> first_arr = {1, 2, 3};
	std::array<int, 4> second_arr = {11, 12, 13, 14};
	std::array<int, 5> thrid_arr = {21, 22, 23, 24, 25};
	print(first_arr);

	print<second_arr.size()>(second_arr);

	print<thrid_arr.size()>(thrid_arr);
	int a[10];
	return 0;
}