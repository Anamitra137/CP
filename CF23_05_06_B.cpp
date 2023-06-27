#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int cnt = 0;
    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == 0) ++cnt;
        else
        {
            mx = max(mx, cnt);
            cnt = 0;
        }
    }
    mx = max(mx, cnt);
    cout << mx << endl;
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