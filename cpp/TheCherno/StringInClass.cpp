#include <iostream>
#include <string>
#include <string.h>

class classWithString {
public:
	char *charStarName;
	std::string stringName;
	classWithString(char *charStar, const std::string &strName) {
		charStarName = charStar;
		stringName = strName;
	}
};

void print(classWithString *object) {
	std::cout << object->charStarName << " is your name" << std::endl << "string name is ==> " << object->stringName << std::endl;
}

int main() {
	classWithString *objectOne = new classWithString((char *)"ivan", "string ivan");
	classWithString *objectTwo = new classWithString((char *)"savan", "string savan");

	print(objectOne);
	print(objectTwo);
	return 0;
}