#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
using namespace std;
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int no_of_transactions, friends;
	cin >> no_of_transactions >> friends;
	int x, y, amount;
	int net[N] = {0};
	while (no_of_transactions--) {
		cin >> x >> y >> amount;
		net[x] -= amount;
		net[y] += amount;
	}

	multiset<int>m;
	for (int i = 0; i < friends; i++) {
		if (net[i] != 0) {
			m.insert(net[i]);
		}
	}
	int cnt = 0;
	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());

		int debit = *low;
		int credit = *high;

		m.erase(debit);
		m.erase(credit);

		int transaction_amount = min(-debit, credit);
		cnt++;

		debit = debit + transaction_amount;
		credit = credit - transaction_amount;

		if (credit != 0) {
			m.insert(credit);
		}
		else if (debit != 0) {
			m.insert(debit);
		}
	}
	cout << cnt;

	return 0;
}
