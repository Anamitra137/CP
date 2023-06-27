#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n, k, g; cin >> n >> k >> g;

    ll total = (1LL*k*g);

    ll val = (g+1)/2 - 1;
    
    if(n*val >= total){
        cout << total << '\n';
        return;
    }
    
    ll rem = total - (n-1)*val;

    rem = rem%g;
    if(rem <= val){
        cout << (n-1)*val + rem << '\n';
        return;
    }
    cout << (n-1)*val - (g-rem) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}