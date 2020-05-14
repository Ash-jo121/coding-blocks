#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
using namespace std;
int arr[501][501] = {0};
int n = 0, m = 0;
int check(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= n) {
		return 0;
	}
	return 1;
}
vector<pair<int, int> > neighbour(int i, int j) {
	vector<pair<int, int> >nbr;
	if (check(i - 1, j - 1)) {
		nbr.push_back(make_pair(i - 1, j - 1));
	}
	if (check(i - 1, j)) {
		nbr.push_back(make_pair(i - 1, j));
	}
	if (check(i - 1, j + 1)) {
		nbr.push_back(make_pair(i - 1, j + 1));
	}
	if (check(i, j - 1)) {
		nbr.push_back(make_pair(i, j - 1));
	}
	if (check(i, j + 1)) {
		nbr.push_back(make_pair(i, j + 1));
	}
	if (check(i + 1, j - 1)) {
		nbr.push_back(make_pair(i + 1, j - 1));
	}
	if (check(i + 1, j )) {
		nbr.push_back(make_pair(i + 1, j));
	}
	if (check(i + 1, j + 1)) {
		nbr.push_back(make_pair(i + 1, j + 1));
	}
	return nbr;
}
int bfs(int i , int j) {
	queue<pair<int, int> > q;
	bool visited[n][m] = {0};
	int dist[n][m] = {0};
	q.push(make_pair(i, j));
	int max_element = 0;
	visited[i][j] = true;
	while (!q.empty()) {
		auto node = q.front();
		q.pop();
		int x = node.first;
		int y = node.second;
		vector<pair<int, int> > nbr = neighbour(x, y);
		for (auto neigh : nbr) {
			int x_new = neigh.first;
			int y_new  = neigh.second;
			if (!visited[x_new][y_new]) {
				q.push(make_pair(x_new, y_new));
				visited[x_new][y_new] = true;
				dist[x_new][y_new] = dist[x][y]  + 1;
				max_element = max(max_element, dist[x_new][y_new]);
			}
		}
	}
	return max_element;
}
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
		cin >> n >> m;
		int max_element = 0;
		int minimum = 2e9;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				max_element = max(arr[i][j], max_element);
				minimum = min(arr[i][j], minimum);
			}
		}
		int min_element = 2e9;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == max_element) {
					int element = bfs(i, j);
					min_element = min(min_element, element);
				}
			}
		}
		if (max_element != minimum) {
			cout << min_element << "\n";
		}
		else {
			cout << "0" << "\n";
		}
	}
	return 0;
}
