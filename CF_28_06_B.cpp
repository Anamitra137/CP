#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    long long a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(k == 1) {
        cout << (n-1)/2 << endl;
        return;
    }
    int cnt = 0;
    for(int i = 1; i <= n-2; i++) {
        if(a[i] > a[i-1] + a[i+1]) cnt++;
    }
    cout << cnt << endl;
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