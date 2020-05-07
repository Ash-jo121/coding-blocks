#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
using namespace std;
int n = 0, k = 0;
int a[N] = {0}, b[N] = {0};
map<int, int>mp;
vector<vector<int> >v;
int c = 0;
int kcount = 0;
int tripleSort() {
	v.clear();
	int flag = 0;
	kcount = 0;
	vector<int>row;
	for (int i = 0; i < n; i++) {
		c = 0;
		if (a[i] == b[i]) {
			continue;
		}
		else {
			int first  = i;
			int second = 0;
			int third = mp[b[i]];
			c = c + 2;;
			int j = i;
			j = j + 1;
			flag = 0;
			while (j < n) {
				if (c == 3) {
					break;
				}
				else if (a[j] == b[j]) {
					j++;
					continue;
				}
				else if (a[j] == b[i]) {
					j++;
					continue;
				}
				else {
					second = j;
					c++;
					j++;
				}
			}
			if (c == 3) {
				if (a[first] > a[second]) {
					//swap both
					int temp = second;
					second = first;
					first = temp;
				}
				row.clear();
				int t = a[first];
				a[first] = a[third];
				a[third] = a[second];
				a[second] = t;
				mp[a[first]] = first;
				mp[a[third]] = third;
				mp[a[second]] = second;
				row.push_back(first + 1);
				row.push_back(second + 1);
				row.push_back(third + 1);
				v.push_back(row);
				flag = 1;
				kcount++;
			}
			else {
				//cout << c << " " << j << "\n";
				flag = 0;
				break;
			}

		}
	}
	return flag;

}
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 0;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		mp.clear();
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
			mp[a[i]] = i;
		}
		sort(b, b + n);
		int condition = tripleSort();
		//cout << condition << "\n";
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		if (kcount > k) {
			cout << "-1" << "\n";
		}
		else if (condition == 0) {
			cout << "-1" << "\n";
		}
		else {
			cout << kcount << "\n";
			for (int i = 0; i < kcount; i++) {
				cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << "\n";
			}
		}
	}
	return 0;
}