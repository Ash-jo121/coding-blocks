#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int fastExponentiation(int a, int b) {
	if (b == 0) {
		return 1 % MOD;
	}
	int smallAns = fastExponentiation(a, b / 2);
	smallAns = (((smallAns) % MOD) * ((smallAns) % MOD)) % MOD;
	if (b & 1) {
		smallAns = ((a % MOD) * (smallAns % MOD)) % MOD;
	}
	return smallAns % MOD;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int ans = fastExponentiation(n, MOD - 2);
	cout << ans;


	return 0;
}