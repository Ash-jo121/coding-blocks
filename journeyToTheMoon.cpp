#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
using namespace std;
map<int, bool> visited;
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
	void dfsHelper(int src, map<int, bool> &visited, int &ct) {
		visited[src] = true;
		ct++;
		int flag = 0;
		for (auto neighbour : adjList[src]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited, ct);
			}
		}
	}
	void journeyTothemoon(map<int, bool> &visited) {
		int flag = 0;
		int sizeArray[V] = {0};
		int i = 0;
		int totalSum = 0;
		while (flag != 1) {
			for (auto node : visited) {
				int ct = 0;
				if (!node.second) {
					dfsHelper(node.first, visited, ct);
					sizeArray[i] = ct;
					i++;
					totalSum = totalSum + ct;
				}
			}
			flag = 1;
		}
		int ans = (totalSum * (totalSum - 1)) / 2;
		for (int j = 0; j < i; j++) {
			if (sizeArray[j] < 2) {
				continue;
			}
			ans = ans - ((sizeArray[j] * (sizeArray[j] - 1)) / 2);
		}
		cout << ans;
	}

};
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p;
	cin >> n >> p;
	Graph g(n);
	while (p--) {
		int s, e;
		cin >> s >> e;
		g.addEdge(s, e);
	}
	map<int, bool> visited;
	for (int i = 0; i < n; i++) {

		visited[i] = false;
	}
	g.journeyTothemoon(visited);




	return 0;
}
