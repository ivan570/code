#include <bits/stdc++.h>

class Person {
	int age;
	std::string name;
public:
	friend void setAge(Person&, int);
	friend int getAge(Person&);
	friend void setName(Person&, std::string);
	friend std::string getName(Person&);
};

void setAge(Person &person, int age) {
	person.age = age;
}

int getAge(Person &person) {
	return person.age;
}

void setName(Person &person, std::string name) {
	person.name = name;
}

std::string getName(Person &person) {
	return person.name;
}

int main() {
	Person person;
	std::string str = "ivan";
	setAge(person, 20);
	setName(person, str);
	std::cout << "age " << getAge(person) << " name " << getName(person);
	return 0;
}