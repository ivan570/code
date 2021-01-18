#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ofstream fout;
    string str, file = "basic";

    // write in file
    cout << "Enter string in file" << endl;
    fout.open(file);
    while (true) {
        getline(cin, str);
        if (str == "-1")
            break;
        fout << str << endl;
    }
    fout.close();

    // read in file
    cout << "read string from file" << endl;
    ifstream fin;
    fin.open(file);
    while (fin) {
        getline(fin, str);
        cout << str << endl;
    }
    return 0;
}