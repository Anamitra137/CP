#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> w(n), p(n);
    for(int i = 0; i < n; ++i) cin >> w[i];
    for(int i = 0; i < n; ++i) cin >> p[i];

    vector<int> curr(x+1, -1);
    curr[0] = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = x; j >= 1; --j)
        {
            if(j >= w[i] && curr[ j-w[i] ] != -1)
            {
                curr[j] = max( curr[j], p[i] + curr[ j-w[i] ] );
            }
        }
    }
    int mx = 0;
    for(int j = 1; j <= x; ++j)
    {
        mx = max(mx, curr[j]);
    }
    cout << mx << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}