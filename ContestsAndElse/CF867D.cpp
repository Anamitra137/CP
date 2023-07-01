#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    if(n&1){
        cout << -1 << '\n';
        return;
    }

    vector<int> ans(n);
    ans[0] = n;
    for(int i = 2; i < n; i += 2) ans[i] = i;
    for(int i = 1; i < n; i += 2) ans[i] = n-i;

    for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}