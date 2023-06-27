#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

constexpr int N = 1000000;
int minfac[N+1];

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

void solve(){
    int n, m; cin >> n >> m;
    if(n == 1)
    {
        cout << "YES" << '\n';
    }
    else if(n <= m || m >= minfac[n])
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    sieve2();
    while(t--)
        solve();

    return 0;
}