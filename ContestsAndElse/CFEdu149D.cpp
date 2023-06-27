#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int val = 1;
    bool pos = true;
    vector<int> ans(n, 0);
    ans[0] = 1;
    bool flag = false;
    for(int i = 1; i < n; ++i)
    {
        if(s[i] == s[0])
        {
            ++val;
        }
        else
        {
            --val;
        }

        if(val < 0 && pos)
        {
            pos = false;
        }
        else if(val > 0 && !pos)
        {
            pos = true;
        }

        if(pos)
        {
            ans[i] = 1;
        }
        else
        {
            ans[i] = 2;
            flag = true;
        }
    }

    if(val != 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        if(flag)
        {
            cout << 2 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
        
        for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
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