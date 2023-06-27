#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    string s; cin >> s;
    char ch = s[0];
    for(int i = 1; i < s.size()/2; ++i)
    {
        if(s[i] != ch)
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}