#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
/*int gcd(int a, int b) {

}*/
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
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	string m;
	cin >> n;
	cin >> m;
	if (n == 0) {
		cout << m;
	}
	else {
		int l = m.length() - 1;
		int s = 0;
		for (int i = 0; i < m.length(); i++) {
			s = (s % n + (((int)(m[i]) % n) * (modualarExponentiation(10, l, n) % n)) % n) % n;
			s = s % n;
			l--;
		}
		cout << s << "\n";
		//cout << gcd(n, s);
	}


	return 0;
}