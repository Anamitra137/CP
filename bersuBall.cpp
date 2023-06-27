#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<double> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];

    vector<vector<double>> dp(n+1, vector<double>(n+1));
    dp[0][0] = 1.0;
    for(int i = 1; i <= n; ++i){
        dp[i][0] = (1-p[i-1])*dp[i-1][0];
        dp[i][i] = p[i-1]*dp[i-1][i-1];
        for(int j = 1; j <= i-1; ++j){
            dp[i][j] = (1-p[i-1])*dp[i-1][j] + p[i-1]*dp[i-1][j-1];
        }
    }

    double ans = 0.0;
    for(int i = (n+1)/2 + 1; i <= n; ++i){
        ans += dp[n][i];
    }

    printf("%.9f\n", ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}