#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	int x = t;
	while (t--) {
		ll n = 0, b = 0;
		cin >> n >> b;
		ll a[n] = {0};
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		cout << a[0] << " " << a[1] << "\n";
		int count = 0;
		for (ll i = 0; i < n; i++) {
			if (b >= a[i]) {
				count++;
				b = b - a[i];
			}
		}
		cout << "Case #" << x - t << ": " << count;
		cout << "\n";
	}




	return 0;
}