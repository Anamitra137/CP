#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int lo = 0, hi = 1e9;
    int ans;
    while(lo <= hi){
        int mid = (lo + hi)/2;

        int cnt = 1;
        long long curr = a[0] + 2*mid;
        for(int i = 0; i < n; ++i){
            if(a[i] > curr){
                ++cnt;
                curr = a[i] + 2*mid;
            }
        }

        if(cnt > 3){
            lo = mid+1;
        }
        else{
            ans = mid;
            hi = mid-1;
        }
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