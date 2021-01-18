#include <iostream>
#include <string>

class Person {
public:
	virtual std::string getPersonName() {
		return "NoBady";
	}
};

class Player : public Person {
	std::string name;
public:
	Player(const std::string &str) {
		name = str;
	}
	std::string getPersonName() override {
		return name;
	}
};

void getName(Person *p) {
	std::cout << "the name of person is " << p->getPersonName() << std::endl;
}

int main() {

	Person *p = new Person();
	std::cout << "for Person ";
	getName(p);

	Player *player = new Player("Ivan Vaghani");
	std::cout << "for Player ";
	getName(player);

	return 0;
}