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
	void dfsHelper(int src, map<int, bool> &visited, int stack[], int &flag) {
		visited[src] = true;
		stack[src] = 1;
		for (auto neighbour : adjList[src]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited, stack, flag);
			}
			else {
				if (stack[neighbour] == 1) {
					flag = 1;
				}
			}
		}
		stack[src] = 0;
	}
	void dfs() {
		map<int, bool> visited;
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}
		int stack[V] = {0};
		int flag = 0;
		dfsHelper(0, visited, stack, flag);
		cout << flag << "\n";
	}

};
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 2);
	g.dfs();



	return 0;
}
