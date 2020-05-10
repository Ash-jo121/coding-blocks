#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
using namespace std;
void floodFill(char diagram[][100], int r, int c, char ch, int x, int y) {
	if (diagram[x][y] != '.') {
		return;
	}
	if (diagram[x][y] == '.') {
		diagram[x][y] = ch;
	}
	if (x > r || y > c ) {
		return;
	}
	if (x <= 0 || y <= 0) {
		return;
	}
	floodFill(diagram, r, c, ch, x + 1, y);
	floodFill(diagram, r, c, ch, x, y + 1);
	floodFill(diagram, r, c, ch, x - 1, y);
	floodFill(diagram, r, c, ch, x, y - 1);



}
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	char diagram[100][100];
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> diagram[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	char ch;
	cin >> ch;
	floodFill(diagram, r, c, ch, x, y);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << diagram[i][j];
		}
		cout << "\n";
	}
	return 0;
}
