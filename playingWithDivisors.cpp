#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 100001
using namespace std;
int a[N] = {0};
int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	int numberOfDivisors = 1;
	cin >> n;
	int product = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = x;
		product = ((product % MOD) * ((x + 1) % MOD)) % MOD;
	}
	if (product & 1) {
		//odd case
		for (int i = 0; i < n; i++) {
			int x = (((a[i] % MOD) * (product % MOD)) % MOD) / 2;
			x = x % MOD;
			numberOfDivisors = ((numberOfDivisors % MOD) * ((x + 1) % MOD)) % MOD;
		}

	}
	else {
		int s = product / 2;
		s = s % MOD;
		for (int i = 0; i < n; i++) {
			int x = ((a[i] % MOD) * (s % MOD)) % MOD;
			numberOfDivisors = (((numberOfDivisors % MOD) * ((x + 1) % MOD))) % MOD;
		}
	}

	cout << numberOfDivisors % MOD;
	return 0;
}