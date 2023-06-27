#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &i: a) cin >> i;
    ll up = 1000000000, lo = 0;
    for(int i = 0; i < n-1; i++) {
        if(a[i] == a[i+1]) continue;
        ll t = (a[i] + a[i+1])/2;
        if(a[i] < a[i+1]) up = min(up, t);
        else if((a[i]+a[i+1])%2 == 1) lo = max(lo, t+1);
        else lo = max(lo, t);
        if(lo > up) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << lo << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}