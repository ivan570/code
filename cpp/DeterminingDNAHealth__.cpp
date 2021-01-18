#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, s;
    cin >> q;
    vector<string> dna(q);
    vector<int> health(q);
    for (int q_time = 0; q_time < q; q_time++)
    {
        cin >> dna[q_time];
    }
    for (int q_time = 0; q_time < q; q_time++)
    {
        cin >> health[q_time];
    }
    cin >> s;
    vector<int> ans;
    for (int s_time = 0; s_time < s; s_time++)
    {
        int start, end;
        string t_dna;
        cin >> start >> end >> t_dna;
        int cur_value = 0;

        for (int i = 0; i < t_dna.size(); ++i)
        {
            vector<string> dna2 = dna;
            for (int l = 1; l < t_dna.size(); ++l)
            {
                string t_str = t_dna.substr(i, l);
                auto f = find(dna2.begin() + start, dna2.begin() + end + 1, t_str);
                while (f != (dna2.begin() + end + 1))
                {
                    int index = int(f - dna2.begin());
                    // cout << "index " << index << "health " << health[index] << " ";
                    cur_value += health[index];
                    dna2[index] = "0";
                    f = find(dna2.begin() + start, dna2.begin() + end + 1, t_str);
                }
            }
        }
        // cout << cur_value << endl;
        ans.push_back(cur_value);
    }

    // for (auto i : ans)
    //     cout << i << " ";
    cout << *min_element(ans.begin(), ans.end()) << " ";
    cout << *max_element(ans.begin(), ans.end());
    return 0;
}
