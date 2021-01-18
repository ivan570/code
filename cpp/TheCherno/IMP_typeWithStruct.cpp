#include <iostream>

struct Data {
	int x, y;
	Data() {
		x = 10;
		y = 20;
	}
	int* getArray() {
		return (&x);
	}
};

int main()
{
	Data data;

	int* array = (int *)(&data);
	std::cout << "using array " << array[0] << " " << array[1] << std::endl;

	int* position_array = data.getArray();
	std::cout << "using position_array " << position_array[0] << " " << position_array[1] << std::endl;

	int x = *(int*)((char*)(&data) + 4);
	std::cout << "data x value is " << x <<std::endl;
 	return 0;
}