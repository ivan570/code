// std::optional in c++17
#include <iostream>
#include <optional>

std::optional<std::string> getStringOFGivenIdIfItIsValid(int id) {
	// valid IDs
	if (id < 90) {
		return "ivankshu";
	}
	// not valid IDs
	return {};
}

int main() {

	std::optional<std::string> string = getStringOFGivenIdIfItIsValid(25);
	std::string ans = string.value_or("pls check id");
	std::cout << ans << std::endl;
	std::cin.get();
	return 0;
}