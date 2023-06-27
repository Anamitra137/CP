#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    int mn = INT_MAX;
    bool oneOdd = false;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        mn = min(mn, x);
        if(x&1) oneOdd = true;
    }

    if(mn&1)
    {
        cout << "YES" << '\n';
    }
    else if(oneOdd)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
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