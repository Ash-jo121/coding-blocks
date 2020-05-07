#include<bits/stdc++.h>
#define int long long
using namespace std;
int fastExponentiation(int a, int b) {
	if (b == 0) {
		return 1;
	}
	int smallAns = fastExponentiation(a, b / 2);
	smallAns = smallAns * smallAns;
	if (b & 1) {
		smallAns = a * smallAns;
	}
	return smallAns;


}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int ans = fastExponentiation(3, 5);
	cout << ans;


	return 0;
}