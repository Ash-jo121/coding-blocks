#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
bool cowPlacement(int a[], int n, int c, int min_separation) {
	int last_cow = a[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - last_cow >= min_separation) {
			last_cow = a[i];
			cnt++;
			if (cnt == c) {
				return true;
			}
		}
	}
	return false;
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
		int n, c;
		cin >> n >> c;
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int s = 0;
		int e = a[n - 1] - a[0];
		int ans = 0;
		while (s <= e) {
			int mid = (s + e) / 2;
			bool canPlaceCow = cowPlacement(a, n, c, mid);
			if (canPlaceCow) {
				s = mid + 1;
				ans = mid;
			}
			else {
				e = mid - 1;
			}
		}
		cout << ans << "\n";
	}



	return 0;
}