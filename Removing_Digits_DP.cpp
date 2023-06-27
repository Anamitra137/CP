#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

int getMaxDigit(int n)
{
    int mx = 0;
    while(n)
    {
        mx = max(mx, n%10);
        n /= 10;
    }
    return mx;
}

void solve(){
    int n; cin >> n;
    if(n/10 == 0) 
    {
        cout << 1 << '\n';
        return;
    }
    vector<int> dp(n+1, 0);
    // vector<int> p(n+1, 0);

    for(int i = 1; i <= n; ++i)
    {
        int mx = getMaxDigit(i);
        dp[i] = 1 + dp[i-mx];
        // p[i] = i-mx;
    }

    cout << dp[n] << '\n';
    // while(n)
    // {
    //     cout << p[n] << ' ';
    //     n = p[n];
    // }
    // cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}