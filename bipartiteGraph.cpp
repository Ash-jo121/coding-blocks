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
	void dfsHelper(int src, map<int, bool> &visited, int *flag, int parentFlag, int &check) {
		visited[src] = true;
		if (parentFlag == 0) {
			flag[src] = 1;
		}
		else if (parentFlag == 1) {
			flag[src] = 2;
		}
		else {
			flag[src] = 1;
		}
		for (auto neighbour : adjList[src]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited, flag, flag[src], check);
			}
			else {
				if (flag[src] == flag[neighbour]) {
					check = 1;
				}
			}
		}
	}

	void dfs() {
		map<int, bool> visited;
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}
		int flag[V];
		int check = 0;
		dfsHelper(0, visited, flag, 0, check);
		cout << check << "\n";
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
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.dfs();


	return 0;
}
