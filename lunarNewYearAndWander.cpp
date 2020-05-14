#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
using namespace std;
class Graph {
	int V;
	list<int> *adjList;
public:
	Graph(int v) {
		V = v;
		adjList = new list<int>[V + 1];
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

	void bfs(int src) {
		priority_queue<int, vector<int>, greater<int> > q;
		bool *visited = new bool[V + 1] {0};
		q.push(src);
		visited[src] = true;
		while (!q.empty()) {
			int node = q.top();
			cout << node << " ";
			q.pop();

			for (int neighbour : adjList[node]) {
				if (!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}
};


int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	int n, m;
	cin >> n >> m;
	Graph g(n);
	while (m--) {
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}
	g.bfs(1);



	return 0;
}