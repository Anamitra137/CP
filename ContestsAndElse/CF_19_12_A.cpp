#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    vector<vector<int>> cnt(2, vector<int>(11, 0));
    for(int d = 0; d <= 10; d++) {
        for(int i = 0; i < n; i++) {
            if(a[i]&(1<<d)) cnt[1][d]++;
            else cnt[0][d]++;
        }
    }
    int mx = 0, mn = 0;
    for(int d = 0; d <= 10; d++) {
        if(cnt[0][d] == 0) mn += (1<<d);
        if(cnt[1][d] != 0) mx += (1<<d);
    }
    cout << (mx-mn) << '\n';
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