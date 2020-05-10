#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
using namespace std;
class Graph {
	int V;
	list<int>*adjList;
public:
	Graph(int v) {
		V = v;
		adjList = new list<int>[V];

	}
	void addEdge(int u, int v, bool bidir = true) {
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}
	void printAdjList() {
		for (int i = 0; i < V; i++) {
			cout << i << "->";
			for (int node : adjList[i]) {
				cout << node << ",";
			}
			cout << endl;
		}
	}
	void bfs(int src, int n, int &ans) {
		vector<int>dis(n + 1, INT_MAX);
		queue<int>q;
		q.push(src);
		dis[src] = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto neighbour : adjList[cur]) {
				if (dis[neighbour] == INT_MAX) {
					//node not visited
					q.push(neighbour);
					dis[neighbour] = dis[cur] + 1;
				}
				else if (dis[neighbour] >= dis[cur]) {
					//backedge
					ans = min(ans, dis[neighbour] + dis[cur] + 1);
				}
			}
		}
	}
};


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);




	return 0;
}