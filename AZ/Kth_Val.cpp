#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
constexpr ll N = 1000000000; // 10^9

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<ll,int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<int> cnt(n+1, 0);
    while(m--) {
        int l, r;
        cin >> l >> r;
        cnt[l-1] += 1;
        cnt[r] -= 1;
    }
    for(int i = 1; i < n; i++) {
        cnt[i] += cnt[i-1];
    }
    sort(a.begin(), a.end());
    
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