#include <bits/stdc++.h>
using namespace std;

int howManyGames(int p, int d, int m, int s) {
    if (s < p)
        return 0;
    int g = 1, temp = s - p;
    while (temp >= p) {
        g++;
        p -= d;
        if (p < m) {
            p = m;
        }
        temp -= p;
    }
    return g;
}

int main() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;
    int result = howManyGames(p, d, m, s);
    cout << result << endl;
    return 0;
}
