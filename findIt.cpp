#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 100001
using namespace std;
int counter[N] = {0}, sum[N] = {0};
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		counter[x]++;
	}
	for (int i = 2; i < N; i++) {
		for (int j = i; j < N; j += i ) {
			sum[i] = sum[i] + counter[j];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		cout << sum[k] << "\n";
	}
	return 0;
}