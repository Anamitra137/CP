#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 998244353;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[1][0] = (1LL*m*(m-1))%MOD;
    dp[1][1] = 0;

    for(int i = 2; i < n; ++i){
        dp[i][0] = ( (1LL*dp[i-1][1]*(m-1))%MOD + (1LL*dp[i-1][0]*(m-2))%MOD )%MOD;
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[n-1][0] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}