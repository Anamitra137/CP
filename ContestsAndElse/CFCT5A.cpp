#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];

    ll asum = 0, bsum = 0;
    for(int i = 0; i < n; ++i) asum += a[i];
    for(int i = 0; i < m; ++i) bsum += b[i];

    if(asum > bsum){
        cout << "Tsondu\n";
    }
    else if(asum < bsum){
        cout << "Tenzing\n";
    }
    else{
        cout << "Draw\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}