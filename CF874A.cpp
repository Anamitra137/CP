#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    char buf[2];
    buf[0] = s[0];
    map<string, int> mp;
    for(int i = 1; i < n; ++i)
    {
        buf[1] = s[i];
        mp[string(buf)]++;
        buf[0] = buf[1];
    }
    cout << mp.size() << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}