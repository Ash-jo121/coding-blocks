#include<bits/stdc++.h>
using namespace std;
int dp[102][102] = {0};

int maxProfit(int arr[], int n, int k) {

	for (int i = 0; i <= n; i++) {
		dp[0][i] = 0;
	}
	for (int i = 0; i <= k; i++) {
		dp[i][0] = 0;
	}
	for (int p = 1; p <= k; p++) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				ans = max(arr[i] - arr[j] + dp[j][p - 1], ans);
			}
			dp[i][p] = max(dp[i - 1][p], ans);
		}
	}
	return dp[n][k];


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
		int n, k;
		cin >> k >> n;
		int arr[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		int ans = maxProfit(arr, n, k);
		cout << ans << "\n";



	}



	return 0;
}