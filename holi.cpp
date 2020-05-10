#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
using namespace std;
class Graph {
	int V;
	list<pair<int, int> > *adjList;
public:
	Graph(int v) {
		V = v;
		adjList = new list<pair<int, int> >[V + 1];
	}
	void addEdge(int u, int v, int w, bool bidir = true) {
		adjList[u].push_back(make_pair(v, w));
		if (bidir) {
			adjList[v].push_back(make_pair(u, w));
		}
	}
	int dfsHelper(int src, bool *visited, int *count, int &ans) {
		visited[src] = true;
		count[src] = 1;
		for (auto neighbour_pair : adjList[src]) {
			int neighbour = neighbour_pair.first;
			int weight = neighbour_pair.second;
			if (!visited[neighbour]) {
				count[src] += dfsHelper(neighbour, visited, count, ans);
				int nx = count[neighbour];
				int ny = V - nx;
				ans += 2 * min(nx, ny) * weight;
			}
		}
		return count[src];
	}
	int dfs() {
		bool *visited = new bool[V + 1] {0};
		int *count = new int[V + 1] {0};
		int ans = 0;
		dfsHelper(1, visited, count, ans);
		return ans;
	}


};

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Graph g(n);
		for (int i = 0; i < n - 1; i++) {
			int s, e, w;
			cin >> s >> e >> w;
			g.addEdge(s, e, w);
		}
		int ans = g.dfs();
		cout << ans << "\n";
	}


	return 0;
}