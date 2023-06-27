#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> cnt(n+1);
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        cnt[a].push_back(b);
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        sort(cnt[i].begin(), cnt[i].end());
        int size = cnt[i].size();
        for(int j = size-1; j >= max(0, size-i); --j)
        {
            ans += cnt[i][j];
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}