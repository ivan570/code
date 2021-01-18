#include <bits/stdc++.h>
using namespace std;

struct Complex {
private:
    float x = 0, y = 0;
public:
    Complex() {}
    Complex(float x) {
        this->x = x;
    }
    Complex(float x, float y) {
        this->x = x;
        this->y = y;
    }
    Complex operator+ (Complex &add)
    {
        Complex temp(add.x + x, add.y + y);
        return temp;
    }
    Complex operator- (Complex &add)
    {
        Complex temp(x - add.x, y - add.y);
        return temp;
    }
    Complex operator* (Complex &add)
    {
        Complex temp(x * add.x, y * add.y);
        return temp;
    }
    Complex operator-- (int)
    {
        Complex temp(x--, y--);
        return temp;
    }
    string print()
    {
        return to_string(x) + " + " + to_string(y) + "i";
    }
};

int main() {
    Complex one(9, 4), two(2, 3);
    Complex temp = one--;
    cout << temp.print();
    return 0;
}
