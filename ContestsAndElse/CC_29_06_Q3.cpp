#include<bits/stdc++.h>

using namespace std;

int no2(long long a) {
    int cnt = 0;
    while(!(a & 1)) {
        a = a>>1;
        cnt++;
    }
    return cnt;
}

void solve(){
    int n; cin >> n;
    long long a[2*n];
    for(int i = 0; i < 2*n; i++) cin >> a[i];
    int cnt[2*n];
    int odd = 0;
    for(int i = 0; i < 2*n; i++) {
        if((cnt[i] = no2(a[i])) == 0) odd++;
    }
    if(odd == n) {cout << 0 << endl; return;}
    if(odd > n) {cout << (odd-n) << endl; return;}
    sort(cnt, cnt + 2*n);
    int ans = 0;
    for(int i = 0; i < 2*n && odd < n; i++) {
        if((ans += cnt[i]) != 0) odd++;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}