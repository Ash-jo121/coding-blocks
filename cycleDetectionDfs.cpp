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
	void dfsHelper(int src, map<int, bool> &visited, int &flag, int parent) {
		visited[src] = true;
		for (auto neighbour : adjList[src]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited, flag, src);
			}
			else if (visited[neighbour] == true && neighbour != parent) {
				flag = 1;
			}
		}
	}
	void dfs() {
		map<int, bool> visited;
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}
		int flag = 0;
		dfsHelper(0, visited, flag, 0);
		cout << flag;
	}


};

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);
	g.dfs();



	return 0;
}
