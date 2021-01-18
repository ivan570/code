#include <iostream>
#include <chrono>
#include <thread>

class Time {

	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<double> complete;
public:
	Time() {
		start = std::chrono::high_resolution_clock::now();
	}

	~Time() {
		end = std::chrono::high_resolution_clock::now();
		complete = end - start;
		std::cout << "time tacken to complete " << complete.count() * 1000 << " ms" << "\n";
	}
};

void times() {
	Time time;
	for (int i = 1; i <= 500; ++i)
		std::cout << "times count is now " << i << "\n";
}

int main()
{
	times();
	return 0;
}