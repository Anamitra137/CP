#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int n;
ll a[400];
ll dp[400][400];

ll rec(int i, int j){
    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    ll cost = (i > 0) ? a[j] - a[i-1] : a[j];
    ll mn = LONG_LONG_MAX;
    for(int k = i; k < j; ++k){
        mn = min(mn, rec(i, k) + rec(k+1, j));
    }

    return (dp[i][j] = mn + cost);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i) a[i] += a[i-1];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) dp[i][j] = -1;
    }

    cout << rec(0, n-1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}