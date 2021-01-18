#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    // write into file
    cout << "write into file" << endl;
    ofstream fout;
    fout.open("2.normal.txt");
    string str;
    while (true) {
        getline(cin, str);
        if (str == "-1")
            break;
        // write function need char* as string and size of string
        fout.write(str.c_str(), str.size());
        fout.write("\n", 1);
    }

    fout.close();

    cout << "read from file" << endl;
    ifstream fin;
    fin.open("2.normal.txt");

    while (fin) {
        char star[50];
        // read need char* and size
        fin.read(star, 50);
        cout << star << endl;
    }
    fin.close();
    return 0;
}
