#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

int dp[100001][3];

void solve(){
    int n; cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; ++i) cin >> b[i];

    for(int i = 0; i < 3; ++i)
    {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; ++i)
    {
        dp[i][0] = max(dp[i-1][0], b[i-1] + i-1);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + b[i-1]);
        dp[i][2] = max(dp[i-1][2], dp[i-1][1] + b[i-1] - i+1);
    }

    cout << dp[n][2] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}