#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

int c[100];
ll dp[1000001];


void solve(){
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> c[i];

    dp[0] = 1;

    for(int j = 0; j < n; ++j)
    {
        for(int i = 1; i <= x; ++i)
        {
            if(c[j] <= i)
            {
                dp[i] = (dp[i] + dp[i-c[j]]) % MOD;
            }
        }
    }

    cout << dp[x] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}