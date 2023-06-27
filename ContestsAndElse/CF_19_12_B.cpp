#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> ph(n);
    ll mx = 0;
    for(auto &i: ph) {cin >> i.second; mx = max(mx, i.second);}
    for(auto &i: ph) cin >> i.first;
    sort(ph.begin(), ph.end());
    ll red = 0;
    for(int i = 0; i < n && k > 0; ) {
        if(ph[i].second - red <= 0) {i++; continue;}
        red += k;
        k -= ph[i].first;
    }
    if(mx - red <= 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}