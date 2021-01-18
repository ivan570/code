#include <iostream>
#include <string>
#include <string.h>

int main() {

	int AGE = 20, ROLL = 900;
	const int *pointer = &AGE; // it is const pointer it will not allow to change to context of this memory location in which pointer is pointing.
	// so it will allow this
	pointer = &ROLL;
	std::cout << "value at Memory loc is pointing... ==> " << *pointer << std::endl;
	// But is will not allow this
	// *pointer = 99; // it will give you error

	int *const c_pointer = &AGE;
	*c_pointer = 45; // it will allow to do this
	std::cout << "value at Memory loc is c_pointing... ==> " << *c_pointer << std::endl;
	// *c_pointer = &ROLL; // it will not allow to do this

	return 0;
}
