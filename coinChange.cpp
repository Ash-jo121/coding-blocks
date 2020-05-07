#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
ll dp[100001][501] = {0};
ll coinChange(int arr[], ll n, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i <= m; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
	}
	//Fill the table
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i - arr[j]) < 0) {
				dp[i][j] = dp[i][j - 1] + 0;
			}
			else {
				dp[i][j] = dp[i][j - 1] + dp[i - arr[j]][j];
			}
		}
	}
	return dp[n][m];

}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		int arr[m + 1] = {0};
		for (int i = 1; i <= m; i++) {
			cin >> arr[i];
		}
		ll n = 0;
		cin >> n;
		ll ans = coinChange(arr, n, m);
		cout << ans % MOD << "\n";
	}
	return 0;
}