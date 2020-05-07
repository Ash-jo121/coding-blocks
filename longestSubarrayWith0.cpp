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
	int prefix[n] = {0}, a[n] = {0};
	int x;
	cin >> x;
	prefix[0] = x;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		prefix[i] = prefix[i - 1] + a[i];
	}
	unordered_map<int, int>mp;
	int length = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (mp.find(prefix[i]) == mp.end()) {
			mp.insert(make_pair(prefix[i], i));
		}
		else {
			length = max(length, i - mp[prefix[i]]);
			if (mp[prefix[i]] == 0) {
				length = length - 1;
			}
		}
	}
	if (prefix[1] == 0) {
		if (prefix[0] != 0) {
			length = length + 1;
		}
	}
	cout << length + 1;
	return 0;
}