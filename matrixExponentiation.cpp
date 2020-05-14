#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
vi b, c;
vector<vector<int> >mulitply(vector<vector<int> >A, vector<vector<int> >B) {
	vector<vector<int> >C(k + 1, vector<int>(k + 1));
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int x = 1; x <= k; x++) {
				C[i][j] = (C[i][j] % MOD + ((A[i][j] % MOD) * (B[i][j] % MOD)) % MOD) % MOD;
			}
		}
	}
	return C;
}
vector<vector<int> > power(vector<vector<int> >A, int p) {
	if (p == 1) {
		return A;
	}
	vector<vector<int> >smallAns = power(A, p / 2);
	smallAns = mulitply(smallAns, smallAns);
	if (p & 1) {
		smallAns = mulitply(A, smallAns);
	}
	return smallAns;

}
int compute(int n) {
	if (n == 0) {
		return 0;
	}
	if (n <= k) {
		return b[n - 1];
	}
	//Matrix exponentiation
	vector<int>F1(k + 1);

	for (int i = 1; i <= k; i++) {
		F1[i] = b[i - 1];
	}
	vector<vector<int> > T(k + 1, vector<int>(k + 1));

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			if (i < k) {
				if (j == i + 1) {
					T[i][j] = 1;
				}
				else {
					T[i][j] = 0;
				}
			}
			else {
				T[i][j] = c[k - j];
			}
		}
	}
	T  = power(T, n - 1);
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		ans = (ans % MOD + ((T[1][i] % MOD) * (F1[i] % MOD)) % MOD) % MOD;
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
		int k;
		cin >> k;
		int x;
		for (int i = 0; i < k; i++) {
			cin >> x;
			b.pb(x);
		}
		for (int i = 0; i < k; i++) {
			cin >> x;
			c.pb(x);
		}
		int n;
		cin >> n;
		cout << compute(n) << "\n";
	}



	return 0;
}