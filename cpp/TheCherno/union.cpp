// unions in c++
// best ways to use unions is to save the memory
#include <iostream>

struct memory_element
{
	int a, b;
};

struct memory
{
	int a, b, c, d, e, f, g, h;
	memory_element& get_element() {
		return *(memory_element*)(&a);
	}
};

struct disk
{
	union 
	{
		struct 
		{
			int a, b, c, d, e, f, g, h;
		};
		struct
		{
			memory_element one, two, three, four;
		};
	};
};

void print_element(const memory_element& ele) 
{
	std::cout << ele.a << " " << ele.b << std::endl;
}

int main()
{
	memory ram = {2, 3, 4, 5, 6, 7, 8, 9};

	memory_element block = ram.get_element();
	print_element(block);


	disk hdd = {11, 12, 13, 14, 15, 16, 17, 18};
	print_element(hdd.one);
	return 0;
}