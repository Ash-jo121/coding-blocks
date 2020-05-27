#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001;
#define vi vector<int>
#define pb push_back
using namespace std;
bool isPossible(int a[], int p, int l, int mid) {
	int s = 0;
	int cnt = 0;
	for (int i = 0; i < l; i++) {
		int k = 1;
		int s = 0;
		while (s + k * a[i] <= mid) {
			s = s + k * a[i];
			cnt++;
			k++;
		}
	}
	//cout << "cnt: " << cnt << " " << "mid: " << mid << "\n";
	if (cnt >= p) {
		return true;
	}
	else {
		return false;
	}
}
int minTime(int a[], int l, int p) {
	int s = 0;
	int e = 0;
	for (int j = 1; j <= p; j++) {
		e = e + j;
	}
	int ans = INT_MAX;
	while (s <= e) {
		int mid = (s + e) / 2;
		//cout << "mid:" << mid << "\n";
		if (isPossible(a, p, l, mid)) {
			ans = min(ans, mid);
			e = mid - 1;
			//cout << "e:" << e << "\n";
		}
		else {
			s = mid + 1;
			//cout << "s:" << s << "\n";
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
		int p;
		cin >> p;
		int l;
		cin >> l;
		int a[l] = {0};
		for (int i = 0; i < l; i++) {
			cin >> a[i];
		}
		cout << minTime(a, l, p) << "\n";

	}



	return 0;
}