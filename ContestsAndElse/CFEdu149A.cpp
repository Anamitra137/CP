#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int x, k; cin >> x >> k;

    if(x%k != 0)
    {
        cout << 1 << '\n';
        cout << x << '\n';
    }
    else
    {
        cout << 2 << '\n';
        cout << (x-1) << ' ' << 1 << '\n';
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