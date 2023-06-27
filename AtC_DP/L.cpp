#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

vector<int> a;
vector<vector<ll>> dp;

ll rec(int i, int j){
    if(i == j) return a[i];

    if(dp[i][j] != -1) return dp[i][j];

    return ( dp[i][j] = max(a[i] - rec(i+1, j), a[j] - rec(i, j-1)) );
}

void solve(){
    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    dp.assign(n, vector<ll>(n, -1));

    cout << rec(0, n-1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}