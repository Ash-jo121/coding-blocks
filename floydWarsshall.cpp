#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
using namespace std;
class Graph {
	int V;
	list<pair<int, int> >*adjList;
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
	void printAdjList() {
		for (int i = 0; i < V; i++) {
			cout << i << "->";
			for (int node : adjList[i]) {
				cout << node << ",";
			}
			cout << endl;
		}
	}
	vector<vi> all_pair_shortest_path() {
		vector<vi> dist(V + 1, vector<int>(V + 1, 2e9));
		for (int i = 1; i <= V; i++) {
			dist[i][i] = 0;
			for (auto node_pair : adjList[i]) {
				int node = node_pair.first;
				int weight = node_pair.second;
				dist[i][node] = weight;
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= V; i++) {
				for (int j = 1; j <= V; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		return dist;
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
