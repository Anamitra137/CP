#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> ans(n, vector<int>(m));
    int curr = 1;
    if(n == 4)
    {
        for(int j = 0; j < m; j += 2)
        {
            for(int i = 0; i < n; ++i)
            {
                ans[i][j] = curr++;
            }
        }
        for(int j = 1; j < m; j += 2)
        {
            for(int i = 0; i < n; ++i)
            {
                ans[i][j] = curr++;
            }
        }
    }
    else{
        for(int i = 0; i < n; i += 2)
        {
            for(int j = 0; j < m; ++j)
            {
                ans[i][j] = curr++;
            }
        }
        for(int i = 1; i < n; i += 2)
        {
            for(int j = 0; j < m; ++j)
            {
                ans[i][j] = curr++;
            }        
        }
    }
    

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j) cout << ans[i][j] << ' ';
        cout << '\n';
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