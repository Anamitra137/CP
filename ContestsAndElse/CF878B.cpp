#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;

    int num = n;
    int cnt = 0;
    while(num)
    {
        num >>= 1;
        ++cnt;
    }

    if(cnt <= k)
    {
        cout << (n+1) << '\n';
    }
    else
    {
        cout << (1LL<<k) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}