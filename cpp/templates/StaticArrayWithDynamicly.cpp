#include <iostream>


template <int SIZE>
class Array
{
	int arr[SIZE];
public:
	Array() 
	{
		std::cout << "obj created " << std::endl;
	}
};

int main()
{
	Array<5> obj_arr;
	return 0;
}