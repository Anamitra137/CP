#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int xa, ya; cin >> xa >> ya;
    int xb, yb; cin >> xb >> yb;
    int xc, yc; cin >> xc >> yc;

    int numE1 = xb - xa, numE2 = xc - xa;
    int numN1 = yb - ya, numN2 = yc - ya;

    int ans = 0;
    if(numE1 > 0 && numE2 > 0 || numE1 < 0 && numE2 < 0) ans += min(abs(numE1), abs(numE2));
    if(numN1 > 0 && numN2 > 0 || numN1 < 0 && numN2 < 0) ans += min(abs(numN1), abs(numN2));
    
    cout << ans+1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}