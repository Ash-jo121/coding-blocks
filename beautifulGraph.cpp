#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
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

	int dfs() {
		map<int, bool> visited;
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}
		int flag[V];
		int check = 0;
		dfsHelper(0, visited, flag, 0, check);
		return check;
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
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n > m;
		Graph g(n);
		while (m--) {
			cin >> s >> e;
			g.addEdge(s, e);
		}
		int check = g.dfs();
		int ans = 0;
		if (check == 1) {
			//Not a bipartite graph
			ans = 0;
		}
		else {
			ans = ((n % MOD) * ((n - 1) % MOD)) % MOD;
			ans = ((2 % MOD) * (ans % MOD)) % MOD;
		}
		cout << ans << "\n";
	}





	return 0;
}