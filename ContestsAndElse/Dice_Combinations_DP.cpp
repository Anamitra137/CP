#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= min(i,6); ++j)
        {
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }

    cout << dp[n] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}