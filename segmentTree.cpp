#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
void pointUpdate(int idx, int inc, int s, int e, int tree[], int index) {
	if (idx > e or idx < s) {
		return;
	}
	if (s == e) {
		tree[index] = tree[index] + inc;
	}
	int mid = (s + e) / 2;
	pointUpdate(idx, inc, s, mid, tree, 2 * index);
	pointUpdate(idx, inc, mid + 1, e, tree, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}
void rangeUpdate(int l, int r, int s, int e, int tree[], int index) {

}
int query(int qs, int qe, int s, int e, int index, int tree[]) {
	//complete overlap
	if (qs <= s and qe <= e) {
		return tree[index];
	}
	//No overlap
	if (qs > e or s > qe) {
		return INT_MAX;
	}
	//partial overlap
	int mid = (s + e) / 2;
	int ans1 = query(qs, qe, s, mid, 2 * index, tree);
	int ans2 = query(qs, qe, mid + 1, 2 * index + 1, tree);
	return min(ans1, ans2);
}
void buildTree(int tree[], int a[], int index, int s, int e) {
	if (s == e) {
		tree[index] = a[s];
		return;
	}
	int mid = (s + e) / 2;
	buildTree(tree, a, 2 * index, s, mid);
	buildTree(tree, a, 2 * index + 1, mid + 1, e);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n] = {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int tree[4 * n + 1] = {0};
	buildTree(tree, a, 1, 0, n - 1);
	for (int i = 1; i <= 13; i++) {
		cout << tree[i] << " ";
	}



	return 0;
}
