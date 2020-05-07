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
	int n;
	cin >> n;
	int a[n] = {0};
	int x;
	cin >> x;
	int xorSum = x;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		xorSum = xorSum ^ a[i];
	}
	int ans = xorSum;
	for (int i = 0; i < n; i++) {
		ans = max(ans, xorSum ^ a[i]);
	}
	cout << ans;



	return 0;
}