#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
using namespace std;
int a[10000] = {0};
int n, q;
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		int max_value = -1;
		map<char, int>mp;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			char ch;
			cin >> ch;
			mp[ch]++;
			max_value = max(max_value, mp[ch]);
			if (mp[ch] > 1) {
				for (int j = 1; j < mp[ch]; j++) {
					a[j]++;
				}
			}
		}
		while (q--) {
			int c;
			cin >> c;
			if (c >= max_value) {
				cout << "0" << "\n";
			}
			else {
				if (c == 0) {
					cout << n << "\n";
				}
				else {
					cout << a[c] << "\n";
				}
			}
		}
	}


	return 0;
}