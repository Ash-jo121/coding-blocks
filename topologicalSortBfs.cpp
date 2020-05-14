#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
using namespace std;
class Graph {
	int V;
	list<int> *adjList;
	int *indegree;
public:
	Graph(int v) {
		V = v;
		adjList = new list<int>[V];
		indegree = new int[V] {0};
	}
	void addEdge(int u, int v) {
		adjList[u].push_back(v);
		indegree[v]++;
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

	void bfs() {
		//Traverse all the nodes of the graph
		queue<int> q;
		bool *visited = new bool[V] {0};
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				visited[i] = true;
			}
		}
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (int neighbour : adjList[node]) {
				indegree[neighbour]--;
				if (indegree[neighbour] == 0) {
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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Graph g(6);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(4, 5);
	g.addEdge(3, 5);
	g.bfs();




	return 0;
}