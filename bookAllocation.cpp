#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
bool isPossible(int a[], int n, int m, int mid) {
	int sum = 0, i = 0;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		sum = sum + a[i];
		if (sum <= mid) {
			continue;
		}
		else if (sum > mid) {
			cnt++;
			sum = a[i];
			if (cnt > m) {
				return false;
			}
		}
	}
	return true;
}
int binarySearch(int a[], int n, int m) {
	if (n < m) {
		return -1;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + a[i];
	}
	int s = a[n - 1];
	int e = sum;
	int ans = INT_MAX;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (isPossible(a, n, m, mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}

	}
	return ans;
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
		int n, m;
		cin >> n >> m;
		int a[n] = {0};
		for (int i = 0; i < n; ++i)
		{
			/* code */
			cin >> a[i];
		}
		cout << binarySearch(a, n, m) << "\n";
	}
	return 0;
}
