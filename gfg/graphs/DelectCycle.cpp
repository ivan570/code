#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool dfd(int start, vector<int> &visited, vector<int> &inStack, vector<int> list[]) {
        if (!visited[start]) {
            inStack[start] = true;
            visited[start] = true;

            for (int &i : list[start]) {
                if (!visited[i] && dfd(i, visited, inStack, list))
                    return true;
                else if (inStack[i])
                    return true;
            }

            inStack[start] = false;
        }
        return false;
    }

    bool isCyclic(int size, vector<int> list[]) {
        vector<int> visited(size, false);
        vector<int> inStack(size, false);
        for (int i = 0; i < size; ++i) {
            if (dfd(i, visited, inStack, list))
                return true;
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
