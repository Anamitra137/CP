#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> ans(n, 0);

    for(int i = 0; i < n; i = i + k)
    {
        ans[i] = 1;
    }

    int cnt = 0;
    for(int i = n-1; i >= 0; --i)
    {
        if(ans[i] == 1)
        {
            ++cnt;
        }
        if(cnt < ceil(1.0*(n-i)/k))
        {
            ans[i] = 1;
            ++cnt;
        }
    }

    // for(int i = 0; i < n; ++i)
    // {
    //     cout << ans[i] << ' ';
    // }
    // cout << '\n';

    cout << cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}