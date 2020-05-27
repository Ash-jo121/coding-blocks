#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
int n;
int bit[N] = {0};
void update(int i, int inc, int n) {
	while (i <= n) {
		bit[i] = bit[i] + inc;
		i = i + (i & -i);
	}
}
void build(int arr[], int n) {
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j <= N) {
			bit[j] = max(bit[j], a[j]);
			j = j + (j & -j);
		}
	}
}
int query(int i) {
	int maxElement = 0;
	while (i > 0) {
		maxElement = max(maxElement, bit[i]);
		i = i & -i;
	}
	return maxElement;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	int arr[n] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	build(arr, n);
	for (int i = 1; i <= n; i++) {
		cout << bit[i] << " ";
	}
	cout << "\n";
	int x;
	cin >> x;
	int ans = query(x);
	cout << ans << "\n";




	return 0;
}