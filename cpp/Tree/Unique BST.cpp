#include <bits/stdc++.h>
using namespace std;

int numTrees(int number) {
    if (number < 2)
        return number;
    int tree[number + 1];
    for (int i = 0; i <= number; ++i)
        tree[i] = 0;
    tree[0] = 1;
    tree[1] = 1;
    for (int i = 2; i <= number; ++i)
        for (int j = 1; j <= i; ++j)
            tree[i] += (tree[j - 1] * tree[i - j]);

    return tree[number];
}

int main() {
    cout << numTrees(384);
    return 0;
}