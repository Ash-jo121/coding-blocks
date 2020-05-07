#include<bits/stdc++.h>
using namespace std;
int dp[101][101] = {0};
int wildcardMatching(string s1, string s2) {
	memset(dp, 0, sizeof(dp));
	int i = 0, j = 0;
	int l1 = s1.length();
	int l2 = s2.length();
	if (s2[i] == '*') {
		for (int j = 0; j < l1; j++) {
			dp[i][j] = 1;
		}
	}
	else if (s2[i] == s2[j]) {
		dp[i][j] = 1;
	}
	else if (s2[i] == '?') {
		dp[i][j] = 1;
	}
	for (int i = 1; i < l2; i++) {
		int j = i;
		if (s2[i] == '*') {
			if (dp[i - 1][j - 1] == 1) {
				for (int j = i; j < l1; j++) {
					dp[i][j] = 1;
				}
			}
		}
		else if (s2[i] == s2[j]) {
			if (dp[i - 1][j - 1] == 1) {
				dp[i][j] = 1;
			}
		}
		else if (s2[i] == '?') {
			if (dp[i - 1][j - 1] == 1) {
				dp[i][j] = 1;
			}
		}
		else if (dp[i][j] == 0) {
			break;
		}
	}

	for (int i = 0; i < l2; i++) {
		for (int j = 0; j < l1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	return dp[l2 - 1][l1 - 1];




}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s1, s2;
	cin >> s1;  		//Normal string
	cin >> s2;		//Encrypted string

	int ans = wildcardMatching(s1, s2);
	if (ans == 1) {
		cout << "MATCHED";
	}
	else {
		cout << "NOT MATCHED";
	}
	return 0;
}