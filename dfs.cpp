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
	void dfsHelper(int src, map<int, bool> &visited) {
		cout << src << " -> ";
		visited[src] = true;
		for (auto neighbour : adjList[node]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited);
			}
		}
	}
	void dfs(int src) {
		map<int, bool> visited;
		for (auto p : adjList) {
			int node = p.first;
			visited[node] = false;
		}
		dfs(src, visited);
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
