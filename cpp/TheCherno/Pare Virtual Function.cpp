#include <iostream>
#include <string>

// it like interface
class InterfaceClass {
public:
	virtual std::string getClassName() = 0;
};

class NormalClass : public InterfaceClass {
public:
	std::string getClassName() override {
		return "NormalClass";
	}
};

class AllPossibleClass : public NormalClass {
public:
	std::string getClassName() override {
		return "AllPossibleClass";
	}
};

void printClassName(InterfaceClass *interfaceClass) {
	std::cout << "The class name is ==> " << interfaceClass->getClassName() << std::endl;
}

int main() {

	NormalClass *normalClass = new NormalClass();
	AllPossibleClass *allPossibleClass = new AllPossibleClass();

	printClassName(normalClass);
	printClassName(allPossibleClass);
	return 0;
}