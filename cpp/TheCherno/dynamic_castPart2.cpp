// dynamic cast
#include <iostream>

// if any class hase virtual method or destructor it will be polymoirphic class type
class Parent {
public:
	virtual void getParent() {}; // it will allow
};

class Son : public Parent {
};

class Daugther : public Parent {
};

int main() {
	Parent* parents = new Son();
	Daugther* daugther = dynamic_cast<Daugther*>(parents);
	return 0;
}
// ivankshu vaghani