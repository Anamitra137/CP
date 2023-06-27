#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7

void solve(){
    int n; cin >> n;

    int lo = 1, hi = 2023;
    int m = -1;
    while(lo <= hi)
    {
        int mid = ((lo + hi)>>1);
        if((mid-1)*mid/2 < n && n <= mid*(mid+1)/2)
        {
            m = mid;
            break;
        }
        else if (n <= (mid-1)*mid/2)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    int t = n - (m-1)*m/2;
    ll ans = 0;
    for(int i = m; i >= 1; --i)
    {
        for(int j = t+i-m; j <= t; ++j)
        {
            if(j >= 1 && j <= i)
            {
                int x = (i-1)*i/2 + j;
                ans += 1LL * x * x;
            }
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