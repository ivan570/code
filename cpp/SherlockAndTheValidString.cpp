#include <bits/stdc++.h>
using namespace std;

void printMap(map<auto, auto> m)
{
    for (auto i : m)
        cout << i.first << "   " << i.second
             << endl;
    cout << endl;
}

int findMax(map<int, int> m)
{
    int maxi = 0;
    for (auto i : m)
    {
        if (i.second > m[maxi])
        {
            maxi = i.first;
        }
    }
    return maxi;
}

string validString(string str)
{
    map<char, int> strChar;
    map<int, int> freq;
    for (auto i : str)
    {
        freq[strChar[i]]--;
        if (freq[strChar[i]] < 0)
        {
            freq.erase(strChar[i]);
        }
        strChar[i]++;
        freq[strChar[i]]++;
    }
    printMap(strChar);
    printMap(freq);

    int f = findMax(freq);
    cout << "max element key " << f << endl;

    int temp = 0;
    for (auto elements : freq)
    {
        if (elements.first != 0 && elements.second != 0 && elements.first != f)
        {
            int x = max(elements.first, elements.second);
            if (elements.second == 1 && elements.first == f + 1)
                x = 1;
            temp += x;
        }
    }
    cout << "temp is " << temp << endl;
    if (temp <= 1)
    {
        return "YES";
    }
    return "NO";
}
int main()
{
    string str;
    cin >> str;
    cout << validString(str) << endl;
    return 0;
}
