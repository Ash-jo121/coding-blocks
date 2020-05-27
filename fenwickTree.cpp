#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
void update(int bit[], int i, int inc, int n) {
	while (i <= n) {
		bit[i] = bit[i] + inc;
		i = i + (i & -i);
	}
}
int* build(int arr[], int n) {
	int bit[n + 1] = {0};
	for (int i = 1; i <= n; i++) {
		update(bit, i, arr[i], n);
	}
	return *bit;


}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int arr[n + 1] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int bit[] = build(arr, n);
	for (int i = 1; i <= n; i++) {
		cout << bit[i] << " ";
	}



	return 0;
}
