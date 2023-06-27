#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(64, 0));
    for(int i = 1; i <= n; ++i)
    {
        dp[i][a[i-1]] = (dp[i][a[i-1]] + 1) % MOD;
        for(int j = 0; j < 64; ++j)
        {
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            dp[i][ j&a[i-1] ] = (dp[i][ j&a[i-1] ] + dp[i-1][j]) % MOD;
        }
    }

    ll ans = 0;
    for(int i = 0; i < 64; ++i)
    {
        if(__builtin_popcountll(i) == k)
        {
            ans = (ans + dp[n][i]) % MOD;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}