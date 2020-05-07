#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
void multiply(int arr[], int &n, int no) {
	int carry = 0;
	for (int i = 0; i < n; i++) {
		int product = arr[i] * no + carry;
		arr[i] = product % 10;
		carry = product / 10;
	}

	while (carry) {
		arr[n] = carry % 10;
		carry = carry / 10;
		n++;
	}
}

void bigFactorial(int number) {
	int a[2000] = {0};
	a[0] = 1;
	int n = 1;
	for (int i = 2; i <= number; i++) {
		multiply(a, n, i);
	}
	//print the array
	for (int i = n - 1; i >= 0; i--) {
		cout << a[i];
	}

}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	bigFactorial(n);






	return 0;
}