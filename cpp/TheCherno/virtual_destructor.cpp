#include <iostream>

class base {
public:
    base() {
        std::cout << "base class created" << std::endl;
    }
    virtual ~base() {
        std::cout << "base class deleted" << std::endl;
    }
};

class child : public base {
public:
    child() {
        std::cout << "child class created" << std::endl;
    }
    ~child() {
        std::cout << "child class deleted" << std::endl;
    }
};

int main() {

    {
        base b;
    }
    std::cout << "--------------------------------------\n";
    {
        child c;
    }
    std::cout << "--------------------------------------\n";
    {
        base *b = new child();
        delete b;
    }
    std::cout << "--------------------------------------\n";
    return 0;
}