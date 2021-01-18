#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main()
{
	cout << endl << endl << endl;
	cout << right << setw(40) << "Enter your choice" << endl;
	cout << right << setw(30) << "" << "1) play the game" << endl;
	cout << right << setw(30) << "" << "2) view high score" << endl;
	cout << right << setw(30) << "" << "3) help" << endl;
	int ch = 3;
	cout << right << setw(30) << "" << "please enter: ";
	cin >> ch;
	cout << endl << endl;
	int qu = 2;
	char ans;
	switch(ch) {
		case 1 :	while (qu <= 10) {
						system("cls");
						string st = "" + to_string(qu) + ".qu";
						ifstream infile(st);
						cout << endl << endl <<endl <<endl;
						while(!infile.eof()) {
							string line;
							getline(infile, line);
							if (line == "exit") {
								cout << endl << endl;
								cout << right << setw(20) << "" << "Enter your ans ";
								cin >> ans;
								system("cls");
								cout << endl << endl <<endl <<endl;
								continue;
							}
							cout << right << setw(20) << "" << line << endl;
						}
						cout << endl << endl;
						cout << right << setw(20) << "" << "Enter your ans ";
						cin >> ans;
						qu = 100;
					}
					break;
		case 2 : cout << "ivan" << endl;
					break;

		case 3 : cout << "vaghani" << endl;
					break;
	}
	return 0;
}
