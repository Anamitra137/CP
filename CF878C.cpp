#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) 
    {
        cin >> a[i];
        if(a[i] <= q) a[i] = 1;
        else a[i] = 0;
    }

    int head = -1, tail = 0;
    ll ans = 0;
    while(tail < n)
    {
        while(tail < n && a[tail] == 0) ++tail;
        head = tail-1;
        while(head+1 < n && a[head+1]) ++head;
        int len = head-tail+1;
        if(len >= k) ans += 1LL*(len-k+1)*(len-k+2)/2;
        
        tail = head+1;
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