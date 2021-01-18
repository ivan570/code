#include <iostream>
#include <string>

class ClassName {
	std::string name;
	int data;
public:
	ClassName(const std::string str) : name(str), data(0) {};
	ClassName(const int data) : name("NoBody"), data(data) {};

	std::string getName() {
		return name;
	}

	int getData() {
		return data;
	}
};

void print(ClassName className) {
	std::cout << "\tname is ==> " << className.getName()
	          << "\n\tdata is ==> " << className.getData() << std::endl;
}

int main() {

	ClassName one = std::string("ivan");
	ClassName two = 23;

	std::cout << "one value::" << std::endl;
	print(one);
	std::cout << "two value::" << std::endl;
	print(two);

	std::cout << "using int value::" << std::endl;
	print(34);
}