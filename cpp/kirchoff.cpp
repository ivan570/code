#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int degree(vector<int> arr) {
	int d = 0;
	for(int i = 0; i < arr.size(); i++)
		d += arr[i];
	return d;
}

vector<vector<int> > kirchoff(vector<vector<int> > graph) {
	int ans;
	for(int i = 0; i < graph.size(); i++){
		int d = degree(graph.at(i));
		graph[i][i] = d;
	}
	for(int i = 0; i < graph.size(); i++) {
		for(int j = 0; j < graph.size(); j++) {
			if(i == j)
				continue;
			else {
				graph[i][j] = graph[i][j] * -1;
			}
		}
	}
	return graph;
}

void printGraph(vector<vector<int> > graph) {
	for(int i = 0; i < graph.size(); i++) {
		for(int j = 0; j < graph.size(); j++) {

			cout << setfill(' ') << setw(10);
			cout << graph[i][j];
		}
		cout << setfill('=') << setw(40);
		cout << endl << '=' << endl;
	}
}

int main() {
	vector<vector<int> > graph = { { 0, 0, 1, 1 },
								   { 0, 0, 1, 1 },
								   { 1, 1, 0, 1 },
								   { 1, 1, 1, 0 }
								};

	graph = kirchoff(graph);
	printGraph(graph);
	return 0;
}
