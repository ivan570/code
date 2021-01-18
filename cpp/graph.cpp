#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void BFS(vector<vector<int>> graph, int start)
{
    int visited[graph.size()] = {0};
    queue<int> que;
    que.push(start);
    visited[start] = 1;
    cout << start << " ";
    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        for (int i = 0; i < graph.size(); ++i)
        {
            if (graph.at(temp).at(i) == 1 && visited[i] == 0)
            {
                cout << i << " ";
                visited[i] = 1;
                que.push(i);
            }
        }
    }
}

void DFS(vector<vector<int>> graph, int start, int visited[])
{
    if (visited[start] == 0)
    {
        visited[start] = 1;
        cout << start << " ";
        for (int i = 0; i < graph.size(); ++i)
        {
            if (visited[i] == 0 && graph.at(start).at(i))
            {
                DFS(graph, i, visited);
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 0, 0, 0, 0, 0},
                                 {1, 0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 1, 0, 1, 0},
                                 {0, 0, 1, 0, 1, 0, 0},
                                 {0, 0, 0, 1, 0, 0, 0},
                                 {0, 0, 1, 0, 0, 0, 1},
                                 {0, 0, 0, 0, 0, 1, 0}};

    cout << "BFS " << endl;
    BFS(graph, 0);
    cout << endl;
    cout << "DFS " << endl;
    int visited[graph.size()] = {0};
    DFS(graph, 0, visited);
    return 0;
}