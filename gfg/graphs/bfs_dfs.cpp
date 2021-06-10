#include<bits/stdc++.h>
using namespace std;

class Graph {
    string name;
    int size;
    vector<vector<int>> list;

    void printQueue(queue<int> qu) {
        cout << "printing queue ==> ";
        while (!qu.empty()) {
            cout << qu.front() << " ";
            qu.pop();
        }
        cout << "\n";
    }
public:
    int getSize() {
        return size;
    }

    string getString() {
        return name;
    }

    void setString(string str) {
        name = str;
    }

    void __init__() {
        list.resize(size);
    }

    void reinit_graph() {
        list.clear();
        __init__();
    }

    Graph(int _size, string _name) {
        size = _size;
        name = _name;
    }

    void addEdge(int u, int v) {
        list[u].push_back(v);
        list[v].push_back(u);
    }

    void dfs(vector<bool> &visited, int start) {
        if (!visited[start]) 
            cout << start << " ";
        visited[start] = true;
        for (int &temp : list[start]) {
            if (visited[temp] == false)
                dfs(visited, temp);
        }
    }

    void findDFS_REC(int start) {
        cout << "rec dfs are ";
        vector<bool> visited(size, false);
        dfs(visited, start);
        cout << "\n";
    }

    void findBFS(int start) {
        vector<bool> visited(size, false);

        queue<int> qu;
        cout << "queue start with " << start << " node ";

        while (start >= 0)  {
            if (!visited[start])
                cout << start << " ";
            visited[start] = true;

            for (int &temp : list[start]) {
                if (!visited[temp])
                    qu.push(temp);
            }

            // printQueue(qu);

            if (qu.empty()) {
                bool f = false;
                for (int i = 0; i < size; ++i) {
                    if (!visited[i]) {
                        start = i;
                        f = true;
                        break;
                    }
                }
                if (!f) {
                    start = -1;
                }
            }

            else {
                start = qu.front();
                qu.pop();
            }
        }

        cout << "\n";
    }

    void findDFS(int start) {
        cout << "Starting DFS with " << start << " node ";

        vector<bool> visited(size, false);
        stack<int> st;

        while (start >= 0) {
            if (!visited[start])
                cout << start << " ";

            visited[start] = true;

            for (int &temp: list[start]) {
                if (!visited[temp])
                    st.push(temp);
            }

            if (st.empty()) {
                bool f = false;
                for (int i = 0; i < size; ++i) {
                    if (!visited[i]) {
                        start = i;
                        f = true;
                        break;
                    }
                }
                if (!f) {
                    start = -1;
                }
            }
            else {
                start = st.top();
                st.pop();
            }
        }

        cout << "\n";
    }
};

int main() {
    Graph graph(5, "Graph_for_BFS");

    graph.__init__();

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(1, 4);
    graph.addEdge(3, 4);

    for (int i = 0; i < 5; ++i)
        graph.findBFS(i);
    cout << "\n";
    for (int i = 0; i < 5; ++i)
        graph.findDFS_REC(i);

    return 0;
}
