#include <iostream>

class Try
{
public:
    int data;
    Try(int data)
    {
        this->data = data;
        std::cout << "Try for data = " << data << std::endl;
    }
    ~Try()
    {
        std::cout << "~Try for data = " << data << std::endl;
    }
};

int main()
{
    std::cout << "before if " << std::endl;
    if (0 == 0)
    {
        static Try tryOne(90);
    }
    std::cout << "after if " << std::endl;
    Try tryTwo(99);
    std::cout << "main end" << std::endl;
}