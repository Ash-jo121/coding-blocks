#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
using namespace std;
int modualarExponentiation(int a, int b, int c) {
	if (b == 0) {
		return 1;
	}
	int smallAns = modualarExponentiation(a, b / 2, c);
	smallAns = (((smallAns % c) * (smallAns % c)) % c);
	if (b & 1) {
		smallAns = ((a % c) * (smallAns % c)) % c;
	}
	return smallAns % c;


}

int factorialModulus(int n) {
	int product = 1;
	for (int i = 1; i <= n; i++) {
		product = ((product % MOD) * (i % MOD)) % MOD;
	}
	return product % MOD;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	int ans1 = factorialModulus(a);
	//cout << ans1 << " ";
	int smallAns2 = factorialModulus(b);
	int ans2 = modualarExponentiation(smallAns2, MOD - 2, MOD);
	int smallAns3 = factorialModulus(a - b);
	int ans3 = modualarExponentiation(smallAns3, MOD - 2, MOD);
	//cout << ans3 << " ";
	int ans = ((ans1 % MOD) * (ans2 % MOD)) % MOD;
	ans = ((ans % MOD) * (ans3 % MOD)) % MOD;
	cout << ans % MOD;
	return 0;
}