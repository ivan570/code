#include <iostream>

class ClassWithMutable {
	int count;
	mutable int m_count;
public:
	void increment() const {
		// count++; // it will give you error
		m_count++; // it will not give you error
	}

	int getM_Count() const {
		return m_count;
	}
};

int main() {

	const ClassWithMutable *classWithMutable = new ClassWithMutable();
	classWithMutable->increment();
	classWithMutable->increment();
	classWithMutable->increment();
	classWithMutable->increment();
	classWithMutable->increment();

	std::cout << classWithMutable->getM_Count();
	return 0;
}