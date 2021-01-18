#include <bits/stdc++.h>
using namespace std;

int check(string str) {

    map<string, int> ch;
    string  special = "!@#$%^&*()-+";
    ch.insert({"numbers", 0});
    ch.insert({"lower", 0});
    ch.insert({"upper", 0});
    ch.insert({"special", 0});
    ch.insert({"NotFinished", 4});

    for (char i : str) {
        if (islower(i) && ch["lower"] == 0) {
            ch["lower"] = 1;
            ch["NotFinished"]--;
        }
        else if (isupper(i) && ch["upper"] == 0) {
            ch["upper"] = 1;
            ch["NotFinished"]--;
        }
        else if (isdigit(i) && ch["numbers"] == 0) {
            ch["numbers"] = 1;
            ch["NotFinished"]--;
        }
        else if ((ispunct(i)) && ch["special"] == 0) {
            ch["special"] = 1;
            ch["NotFinished"]--;
        }
    }
    return ch["NotFinished"];
}

int main() {
    int n;
    string str;
    cin >> n >> str;
    if (str.length() < 6) {
        int ret = 6 - str.length();
        int temp = check(str);

        if (ret < temp)
            ret = temp;
        cout << ret << endl;
    }
    else {
        cout << check(str) << endl;
    }

    return 0;
}
