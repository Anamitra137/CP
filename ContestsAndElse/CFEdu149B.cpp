#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int maxcnt = 1, cnt = 1;
    char curr = s[0];
    for(int i = 1; i < n; ++i)
    {
        if(s[i] == curr)
        {
            ++cnt;
        }
        else
        {
            maxcnt = max(maxcnt, cnt);
            curr = s[i];
            cnt = 1;
        }
    }
    maxcnt = max(maxcnt, cnt);

    cout << (maxcnt+1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}