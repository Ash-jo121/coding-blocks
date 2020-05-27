#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
int binarySearch_first(int arr[], int n, int key) {
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == key) {
			if (arr[mid - 1] == key) {
				e = mid - 1;
			}
			else {
				return mid;
			}
		}
		else if (arr[mid] > key) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return -1;
}
int binarySearch_last(int arr[], int n, int key) {
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == key) {
			if (arr[mid + 1] == key) {
				s = mid + 1;
			}
			else {
				return mid;
			}
		}
		else if (arr[mid] > key) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
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
	int arr[] = {1, 2, 5, 8, 8, 8, 8, 10, 12};
	int n = sizeof(arr) / sizeof(int);
	int key;
	cin >> key;
	int first_occurence = binarySearch_first(arr, n, key);
	int last_occurence = binarySearch_last(arr, n, key);
	cout << first_occurence << "\n";
	cout << last_occurence << "\n";


	return 0;
}