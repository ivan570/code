#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    map<int, int> queries;
    map<int, int> frequency;
    for (int n_time = 0; n_time < n; ++n_time) {
        int first, second;
        cin >> first >> second;
        if (first == 1) {
            int x = queries[second];
            frequency[x]--;
            if (frequency[x] < 0)
                frequency[x] = 0;
            queries[second] ++;
            x = queries[second];
            frequency[x] ++;
        }
        if (first == 2) {
            int x = queries[second];
            frequency[x]--;
            if (frequency[x] < 0)
                frequency[x] = 0;

            queries[second] --;
            if (queries[second] < 0)
                queries[second] = 0;

            x = queries[second];
            frequency[x] ++;
        }
        if (first == 3) {
            if (frequency[second] > 0) {
                cout << "1" << endl;
            }
            else {
                cout << "0" << endl;
            }
        }
    }

    // it's Ivan
    return 0;
}
