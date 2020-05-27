#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
float squareRoot(float n, float p) {
	float s = 0.0;
	float e = n;
	float ans = 0;
	while (s <= e) {
		float mid = (s + e) / 2;
		if (mid * mid == n) {
			return mid;
		}
		else if (mid * mid < n) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}

	}

	//Floating value
	float inc = 0.1;

	for (float i = 0; i < p; i++) {
		while (ans * ans <= n) {
			ans = ans + inc;
		}
		ans = ans - inc;
		inc = inc / 10;
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
	float n;
	cin >> n;
	float p;
	cin >> p;
	float ans = squareRoot(n, p);
	cout << ans;


	return 0;
}
