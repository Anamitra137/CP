#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> p(n, 0);
    p[0] = a[0];
    for(int i = 1; i < n; ++i) p[i] = p[i-1] + a[i];

    ll ans = 0;
    for(int l = 0; l <= 2*k; l += 2)
    {
        int r = n - 1 - k + (l/2);
        ll sum = p[r] - (l > 0 ? p[l-1] : 0);
        ans = max(ans, sum);
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