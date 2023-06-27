#include<bits/stdc++.h>

using namespace std;

long long mod(long long n, long long m) {
    long long val = n % m;
    if(val == 0) return 0;
    if(val < 0) val += m;
    return max(val, m-val);
}


void solve(){
    long long n, m; cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long mx = a[0];
    for(int i = 1; i < n; i++) mx = max(mx, a[i]);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, mx + a[i] + mod(mx-a[i], m));
    }
    cout << ans << endl;
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