#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];

    int i1, i2, in;
    for(int i = 0; i < n; ++i)
    {
        if(p[i] == 1) i1 = i;
        if(p[i] == 2) i2 = i;
        if(p[i] == n) in = i;
    }

    int mx = max(i1, max(i2, in));
    int mn = min(i1, min(i2, in));

    if(in != mx && in != mn)
    {
        cout << 1 << ' ' << 1 << '\n';
    }
    else if(i1 != mx && i1 != mn)
    {
        cout << i1+1 << ' ' << in+1 << '\n';
    }
    else
    {
        cout << i2+1 << ' ' << in+1 << '\n';
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