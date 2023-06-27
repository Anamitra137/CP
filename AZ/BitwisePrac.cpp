#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    int cnt[31];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i) 
    {
        int x; cin >> x;
        for(int j = 0; j < 31; ++j)
        {
            if((x>>j)&1) ++cnt[j];
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int num = 0;
        for(int j = 0; j < 31; ++j)
        {
            if(cnt[j]) num += (1<<j), --cnt[j];
        }
        ans += 1LL*num*num;
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