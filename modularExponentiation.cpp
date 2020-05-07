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
		smallAns = ((a % c) * (smallAns % c));
	}
	return smallAns % c;


}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b, c;
	cin >> a >> b >> c;
	int ans = modualarExponentiation(a, b, c);
	cout << ans % c;
	return 0;
}