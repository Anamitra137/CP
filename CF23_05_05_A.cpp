#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7


void solve(){
    int n; cin >> n;
    vector<int> l(n);
    for(int i=0; i<n; i++) cin >> l[i];

    sort(l.begin(), l.end());

    int ans = 0;
    int lastVal = 0, lastIdx = n;
    for(int i = 0; i < n; ++i)
    {
        if(lastVal != l[i])
        {
            lastVal = l[i];
            lastIdx = i;
        }

        if(l[i] > n-1-i)
        {
            ans = n - lastIdx;
            break;
        }
    }
    for(int i = n - 1; i >= lastIdx; --i)
    {
        if(l[i] <= ans) 
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << ans << endl;
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