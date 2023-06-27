#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> cnt(n, 0);
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        ++cnt[u-1];
        ++cnt[v-1];
    }
    int xy = 0, x = 0, x_cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(cnt[i] == 1) ++xy;
        else 
        {
            if(x_cnt == 0)
            {
                x = cnt[i];
                ++x_cnt;
            }
            else if(x == cnt[i])
            {
                ++x_cnt;
            }
        }
    }
    if(x_cnt == n - xy)
    {
        cout << x << ' ' << (x-1) << endl;
    }
    else
    {
        if(x_cnt == 1)
        {
            cout << x << ' ' << xy/x << endl;
        }
        else
        {
            cout << xy/(x-1) << ' ' << (x-1) << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}