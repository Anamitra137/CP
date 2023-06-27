#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) cin >> g[i][j];

    if(g[0][0] == '*' || g[n-1][n-1] == '*')
    {
        cout << 0 << '\n';
        return;
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = 1;
    for(int i = 1; i < n; ++i)
    {
        if(g[0][i] == '.') dp[0][i] = 1;
        else break;
    }
    for(int i = 1; i < n; ++i)
    {
        if(g[i][0] == '.') dp[i][0] = 1;
        else break;
    }
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            if(g[i][j] == '.') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[n-1][n-1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}