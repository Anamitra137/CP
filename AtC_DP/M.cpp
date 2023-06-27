#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(k+1));
    vector<vector<int>> pre(n+1, vector<int>(k+1));

    for(int i = 0; i <= n; ++i) {pre[i][0] = 1; dp[i][0] = 1;}
    for(int j = 1; j <= k; ++j) {pre[0][j] = 1; dp[0][j] = 1;}

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            dp[i][j] = pre[i-1][j];
            if(j >= a[i-1]+1) dp[i][j] = (dp[i][j] - pre[i-1][j - a[i-1] - 1] + MOD)%MOD;
            pre[i][j] = (pre[i][j-1] + dp[i][j])%MOD;
        }
    }

    cout << dp[n][k] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}