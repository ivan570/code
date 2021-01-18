
#include <bits/stdc++.h>
using namespace std;

void print_1D_Vector(vector<auto> total) {
    for (auto i : total) {
        cout << i << " ";
    }
    cout << endl;
}

int capacity(vector<vector<int>> container, int i) {
    int sum = 0;
    for (int j = 0; j < container[i].size(); ++j) {
        sum += container[i][j];
    }
    return sum;
}

int numberOf(vector<vector<int>> container, int j) {
    int sum = 0;
    for (int i = 0; i < container[j].size(); ++i) {
        sum += container[i][j];
    }
    return sum;
}

vector<int> totalCapacity(vector<vector<int>> container) {
    vector<int> totalCapacityVector (container.size(), 0);
    for (int i = 0; i < container.size(); ++i) {
        totalCapacityVector[i] = capacity(container, i);
    }
    return totalCapacityVector;
}

vector<int> totalNumberOf(vector<vector<int>> container) {
    vector<int> totalNumberOfVcetor (container.size(), 0);
    for (int i = 0; i < container.size(); ++i) {
        totalNumberOfVcetor[i] = numberOf(container, i);
    }
    return totalNumberOfVcetor;
}

string organizingContainers(vector<vector<int>> container) {
    vector<int> capacityVector =  totalCapacity(container);
    vector<int> numberOfVector = totalNumberOf(container);
    sort(capacityVector.begin(), capacityVector.end());
    sort(numberOfVector.begin(), numberOfVector.end());
    for (int i = 0; i < capacityVector.size(); ++i) {
        if (capacityVector[i] != numberOfVector[i]) {
            return "Impossible";
        }
    }
    return "Possible";
}

int main() {
    int q;
    cin >> q;
    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        vector<vector<int>> container(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                    cin >> container[i][j];

        string result = organizingContainers(container);

        cout << result << endl;
    }

    return 0;
}
