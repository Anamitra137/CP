#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    string ans;
    for(int i = 0; i < n;)
    {
        ans.push_back(s[i]);
        int j = i+1;
        while(s[j] != s[i]) ++j;
        i = j+1;
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