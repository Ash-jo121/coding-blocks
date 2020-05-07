#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
using namespace std;

vector<int> primeSieve(int *p) {

	p[0] = p[1] = 0;
	p[2] = 1;

	//Let us Mark all Odd Numbers as Prime(Initialisations)
	for (int i = 3; i < N; i += 2) {
		p[i] = 1;
	}

	//Sieve Login to mark non prime numbers as 0
	//1. Optimsation : Iterate only over odd Numbers
	for (int i = 3; i < N; i += 2) {

		if (p[i]) {
			//Mark all the multiples of that number as not prime.
			//2. Optimisation Take a jump of 2i starting from i*i
			for (int j = i * i; j < N; j += 2 * i) {
				p[j] = 0;
			}
		}

	}
	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; i <= N; i += 2) {
		if (p[i] == 1) {
			primes.push_back(i);
		}
	}
	return primes;
}
vector<int> factorize(int m, vector<int> &primes) {

	vector<int> factors;
	factors.clear();
	int n = m;
	int i = 0;
	int p = primes[0];
	factors.push_back(1);
	while (p * p <= m) {
		if (m % p == 0) {
			factors.push_back(p);
			while (m % p == 0) {
				m = m / p;
			}
		}
		i++;
		p = primes[i];
	}

	//One Last Check for A prime
	if (m != 1) {
		factors.push_back(m);
	}
	if (m != n) {
		factors.push_back(n);
	}
	return factors;
}
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int p[N] = {0};
	vector<int> primes = primeSieve(p);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vector<int> factors = factorize(x, primes);
		if (factors.size() == 3) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}



	return 0;
}