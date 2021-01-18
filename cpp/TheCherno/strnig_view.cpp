// string fast 
#include <iostream>
#include <string>

static int number = 0;
void* operator new(size_t size) {
	number++;
	std::cout << ">==***==< " << size << std::endl;
	return malloc(size);
}

void printString(const std::string_view &str) {
	std::cout << "=:>=:>=:>=:> " << str << " <:=<:=<:=" << std::endl;
}

int main() {

	std::string str = "one menory";
	
	std::string_view sub_str = std::basic_string_view(str.c_str() + 4);
	printString(sub_str);

	std::cout << "\n\tno of allocation are ====*****==== " << number << std::endl;
	std::cin.get();
	return 0;
}