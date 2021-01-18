#include <iostream>

// static variables can not be initialized using constructors.
// static variable inside a class should be initialized explicitly.

class Node
{
public:
    static int data;
};

// line one
int Node::data = 10;

int main()
{
    Node node;
    // it will give error if [line one] tage is not thier.
    // because thier is no space for Node::data in memory we have to give it explicitly.
    // without [line one] if we do given below it will failed in complie time.
    node.data = 90;
    std::cout << node.data << " " << std::endl;
}