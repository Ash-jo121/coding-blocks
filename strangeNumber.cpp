#include<bits/stdc++.h>
#define ll long long
#define MAX 100000
using namespace std;
ll p[MAX] = {0};
ll x = 0, k = 0;
vector<ll> primes;
vector<ll> factors;
int t = 0;
void primeSieve() {

    p[0] = p[1] = 0;
    p[2] = 1;

    //Let us Mark all Odd Numbers as Prime(Initialisations)
    for (ll i = 3; i <= MAX; i += 2) {
        p[i] = 1;
    }

    //Sieve Login to mark non prime numbers as 0
    //1. Optimsation : Iterate only over odd Numbers
    for (ll i = 3; i <= MAX; i += 2) {

        if (p[i]) {
            //Mark all the multiples of that number as not prime.
            //2. Optimisation Take a jump of 2i starting from i*i
            for (ll j = i * i; j <= MAX; j += 2 * i) {
                p[j] = 0;
            }
        }

    }
    primes.push_back(2);
    for (int i = 3; i <= MAX; i += 2) {
        if (p[i] == 1) {
            primes.push_back(i);
        }
    }
    //return primes;
}

void factorize() {

    factors.clear();

    int i = 0;
    int p = primes[0];

    while (p * p <= x) {
        if (x % p == 0) {
            factors.push_back(p);
            x = x / p;
            while (x % p == 0) {
                factors.push_back(p);
                x = x / p;
            }
        }
        i++;
        p = primes[i];
    }

    //One Last Check for A prime
    if (x != 1) {
        factors.push_back(x);
    }
    //return factors;
}

int main() {
    primeSieve();
    cin >> t;
    while (t--) {
        cin >> x >> k;
        factorize();
        if (factors.size() >= k) {
            cout << "1" << "\n";
        }
        else {
            cout << "0" << "\n";
        }


    }
    return 0;
}