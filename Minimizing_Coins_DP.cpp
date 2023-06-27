#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

int c[100];
int dp[1000001];

void solve(){
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> c[i];

    dp[0] = 0;
    for(int val = 1; val <= x; ++val)
    {
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            if(val >= c[i] && dp[val-c[i]] != -1)
            {
                ans = min(ans, dp[val-c[i]] + 1);
            }
        }
        if(ans == INT_MAX) ans = -1;
        dp[val] = ans;
    }
    
    cout << dp[x] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}