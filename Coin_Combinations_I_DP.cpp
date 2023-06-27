#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

int c[100];
int n;
int memo[1000001];

int dp(int val)
{
    if(val == 0) return 1;
    // else if(val < 0) return 0;

    if(memo[val] != -1) return memo[val];
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(val >= c[i])
        {
            ans = (ans + dp(val - c[i])) % MOD;
        }
    }

    return (memo[val] = ans);
}

void solve(){
    int x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> c[i];
    memset(memo, -1, sizeof(memo));
    
    cout << dp(x) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}