#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    int n, W; cin >> n >> W;
    vector<int> w(n), p(n);
    for(int i = 0; i < n; ++i) cin >> w[i] >> p[i];

    int P = 0;
    for(int i = 0; i < n; ++i) P += p[i];
    vector<vector<int>> dp(n+1, vector<int>(P+1));

    for(int i = 0; i <= n; ++i) dp[i][0] = 0;
    for(int j = 1; j <= P; ++j) dp[0][j] = W+1;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= P; ++j){
            int l = dp[i-1][j];
            int r = (j >= p[i-1]) ? dp[i-1][j-p[i-1]] : W+1;
            dp[i][j] = min(W+1, min(l, r+w[i-1]));
        }
    }

    int ans = 0;
    for(int j = 1; j <= P; ++j){
        if(dp[n][j] <= W) ans = j;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}