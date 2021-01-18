#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Node {
    int data;
public:
    Node() {
        data = 0;
    }
    Node(int data) {
        this->data = data;
    }
    int getData() {
        return this->data;
    }
    void setData(int data) {
        this->data = data;
    }
};

void readFile() {
    Node *node;
    ifstream in;
    in.open("file.txt");
    
    int count = 1;
    while (in) {
        in.read((char *)node, sizeof(Node));
        cout << node->getData() << " ";
        count++;
    }
    cout << "\ncount " << count << endl;
    in.close();
}

void writeFile(int data) {
    Node *node = new Node(data);
    ofstream out;
    out.open("file.txt", ios::app);

    out.write((char *)node, sizeof(Node));

    out.close();
}

int main() {

    writeFile(90);
    writeFile(89);

    readFile();
    return 0;
}