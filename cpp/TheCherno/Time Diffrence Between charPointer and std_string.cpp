#include <iostream>
#include <chrono>

class Time {
private:
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<float> duration;
public:
	Time() {
		start = std::chrono::high_resolution_clock::now();
	}
	~Time() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << "time is " << duration.count() * 1000.0f << " ms" << std::endl;
	}
};

int main() {
	int times = 1000;
	{
		Time time;
		for (int i = 0; i < times; ++i)
			std::string str = "ivankshu";
	}
	std::cout << "=*=*=*=*=*=*=\n";
	{
		Time time;
		for (int i = 0; i < times; ++i)
			const char* str = "ivankshu";
	}
	std::cin.get();
	return 0;
}