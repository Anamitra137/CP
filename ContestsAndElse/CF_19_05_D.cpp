#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(k == n) {cout << 0 << endl; return;}
    long long d = 0;
    for(int i = 0; i < n; i++) {
        d += a[i];
    }
    // long long red = 0;
    // for(int i = n-1; i >= n-k; i--) {
    //     red += a[i];
    // }
    for(int i = n-k; i <= n-1; i++) {
        long long mx = a[i];
        for(int j = i-1)
    }

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