#include <bits/stdc++.h>
using namespace std;

template <typename T>

T getMax(T x, T y) {
	return x > y ? x : y;
}

string getMax(string one, string two) {
	return one.size() > two.size() ? one : one.size() == two.size() ? one > two ? one : two : two;
}

int main() {

	string ivan = "ivan", savan = "savan";
	cout << getMax(ivan, savan) << endl;
	return 0;
}