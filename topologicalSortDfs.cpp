#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
using namespace std;
class Graph {
	int V;
	list<int>*adjList;
public:
	Graph(int v) {
		V = v;
		adjList = new list<int>[V];

	}
	void addEdge(int u, int v) {
		adjList[u].push_back(v);
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
	void dfsHelper(int src, map<int, bool> &visited, list<int> &ordering) {
		visited[src] = true;
		for (auto neighbour : adjList[src]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited, ordering);
			}
		}
		list.push_front(src);
	}
	void dfs(int src) {
		map<int, bool> visited;
		list<int>ordering;
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}
		for (auto p : adjList) {
			int src = p.first;
			dfsHelper(src, visited, ordering);
		}
	}

};
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	return 0;
}
