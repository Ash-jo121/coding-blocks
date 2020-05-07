#include<bits/stdc++.h>
using  namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {7, 4, 9, 1, 2, 6, 4};
	int n = sizeof(a) / sizeof(int);
	sort(a, a + n);
	cout << a[0];

	return 0;
}