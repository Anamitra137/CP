#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> p(n, vector<int>(31, 0));
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        for(int j = 0; j < 31; ++j)
        {
            if((x>>j)&1) 
            {
                p[i][j] = 1;
            }
            if(i > 0) p[i][j] += p[i-1][j];
        }
    }

    int q; cin >> q;
    while(q--)
    {
        int l, r; cin >> l >> r;
        ll x1 = 0, x2 = 0, x3 = 0;
        
        for(int i = 0; i < 31; ++i)
        {
            int setBits = p[r-1][i] - (l > 1 ? p[l-2][i] : 0);
            if(setBits < r-l+1-setBits)
            {
                x1 += (1<<i);
            }
            if(setBits < r-l+1)
            {
                x2 += (1<<i);
            }
            if(setBits > 0)
            {
                x3 += (1<<i);
            }
        }
        cout << x1 + x2 + x3 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}