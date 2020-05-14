#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> v;
	v.pb(2);
	v.pb(4);
	v.pb(3);
	v.pb(5);
	v.pb(7);
	v.pb(8);
	for (int neighbour : v) {
		cout << neighbour << " ";
	}




	return 0;
}