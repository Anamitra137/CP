#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int mn = a[0], mx = a[0];
    for(int i = 1; i < n; ++i)
    {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    if(mn < 0)
    {
        cout << mn << '\n';
    }
    else
    {
        cout << mx << '\n';
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