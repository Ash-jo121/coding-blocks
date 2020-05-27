#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
int binarySearch(int a[], int n) {
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			return mid;
		}
		else if (a[mid] >= a[s]) {
			if (key >= a[s] and key <= a[mid]) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		else {
			if (key >= a[mid] and key <= a[e]) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
	}
	return -1;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif




	return 0;
}
