#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
class Node {
public:
	char data;
	unordered_map<char, Node*>children;
	bool terminal;

	Node(char d) {
		data = d;
		terminal = false;
	}

};

class Trie {
	Node *root;
	int cnt;

public:
	Trie() {
		root = new Node('\0');
		cnt = 0;
	}

	void insert(char *w) {
		Node* temp = root;
		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			if (temp ->children.count(ch)) {
				temp = temp->children(ch);
			}
			else {
				Node* n = new Node(ch);
				temp->children(ch) = n;
				temp = n;
			}

		}
		temp->terminal = true;
	}

	bool find(char *w) {
		Node* temp = root;
		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			if (temp->children.count(ch)) {
				return false;
			}
			else {
				temp = temp->children(ch);
			}
		}
		return temp->terminal;
	}
};
string convertToBinary(int x) {


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
	int x;
	cin >> x;
	Trie t;




	return 0;
}
