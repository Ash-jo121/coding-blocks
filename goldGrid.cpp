#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
using namespace std;
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;	//number of coins
	cin >> n;
	int r;	//number of rows
	cin >> r;
	int diagram[r][r] = {0};
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		diagram[x - 1][y - 1] = 1;
	}
	solveGoldGrid(diagram, n, r);




	return 0;
}
