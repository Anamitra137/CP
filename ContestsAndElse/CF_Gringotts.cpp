#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    ll s, g, n; cin >> s >> g >> n;
    
    if(g >= 17*s)
    {
        cout << n << '\n';
        return;
    }

    ll l = s * g /__gcd(s, g);
    ll cnt = n*s/l;

    ll ans = n + cnt*(17*(l/g) - l/s);
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