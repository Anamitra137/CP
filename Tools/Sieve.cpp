#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 1000000; // 10^6
bool isprime[N+1];
int minfac[N+1];
int numdiv[N+1];

void sieve1() {
    isprime[0] = isprime[1] = false;
    for(int i = 2; i <= N; i++) isprime[i] = true;
    for(int i = 2; i*i <= N; i++) {
        if(isprime[i]) {
            for(int j = i*i; j <= N; j += i) isprime[j] = false;
        }
    }
}

void sieve2() {
    minfac[0] = minfac[1] = 1;
    for(int i = 2; i <= N; i++) minfac[i] = i;
    for(int i = 2; i*i <= N; i++) {
        if(minfac[i] == i) {
            for(int j = i*i; j <= N; j += i) {
                if(minfac[j] == j) minfac[j] = i;
            }
        }
    }
}

void sieve3() {
    numdiv[0] = -1;
    for(int i = 1; i <= N; ++i) numdiv[i] = 1;
    for(int i = 2; i <= N; ++i)
    {
        for(int j = 1; j*i <= N; ++j)
        {
            ++numdiv[j*i];
        }
    }
}

vector<int> prime_factors(int n) {
    vector<int> factors;
    while(n > 1) {
        int f = minfac[n];
        factors.push_back(f);
        while(f == minfac[n]) n /= f;
    }
    return factors;
}

int main() {
    // sieve1();
    sieve2();
    auto a = prime_factors(473*11);
    for(auto i : a) cout << i << ' ';
    cout.put('\n');

    return 0;
}