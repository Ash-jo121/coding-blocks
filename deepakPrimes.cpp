#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 100000000
using namespace std;
int p[N] = {0};
int n;
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
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> primes = primeSieve(p);
	cin >> n;
	cout << primes[n - 1];

	return 0;
}