#include <queue>
#include <vector>
#include <iostream>

#define MAX_SIZE 500003
#define  pair std::pair<int, int>

bool visited[MAX_SIZE] = {false};

struct compare {
    bool operator()(const pair &one, const pair &two) {
        if (one.first < two.first)
            return true;
        else if (one.first > two.first)
            return false;
        else
            return one.second > two.second;
    }
};

int main() {
    std::priority_queue<pair, std::vector<pair >, compare> queue;
    int n, index = 1, cur = 1;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int ch;
        std::cin >> ch;
        if (ch == 1) {
            int value;
            std::cin >> value;
            queue.push({value, index});
            index++;
        } else if (ch == 2) {
            while (visited[cur])
                cur++;
            std::cout << cur << " ";
            visited[cur] = true;
        } else if (ch == 3) {
            while (visited[queue.top().second])
                queue.pop();
            std::cout << queue.top().second << " ";
            visited[queue.top().second] = true;
        }
    }
    return 0;
}