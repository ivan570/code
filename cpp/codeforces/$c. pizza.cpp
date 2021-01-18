#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int t, p, n, m, p2;
bool vis[500010];
priority_queue<pair<int, int> > pq;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 1) {
			scanf("%d", &m);
			pq.push({m, -p});
			p++;
		}
		else if (n == 2) {
			while (vis[p2]) p2++;
			printf("%d ", p2 + 1);
			vis[p2] = true;
		}
		else {
			while (vis[-pq.top().second]) pq.pop();
			printf("%d ", -pq.top().second + 1);
			vis[-pq.top().second] = true;
		}
	}
	return 0;
}