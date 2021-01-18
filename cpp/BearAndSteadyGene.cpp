#include <bits/stdc++.h>
using namespace std;

int steadyGene(string gene) {
    string acgt = "ACGT";
    int n = gene.size() / 4, ans = 0;

    map<char, int> ch;
    map<char, int> cur_ch;
    for (char i : acgt) {
        ch[i] = 0;
        cur_ch[i] = 0;
    }
    for (char i : gene) {
        ch[i]++;
    }
    for (int i = 0; i < 4 * n; ++i) {
        cur_ch[gene[i]]++;
        if (cur_ch[gene[i]] > n) {
            char temp = gene[i];
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string gene;
    cin >> gene;

    int result = steadyGene(gene);
    cout << result << endl;

    return 0;
}
