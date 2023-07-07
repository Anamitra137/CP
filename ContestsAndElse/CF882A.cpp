#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> diff(n-1);
    for(int i = 1; i < n; ++i){
        diff[i-1] = abs(a[i-1] - a[i]);
    }

    sort(diff.begin(), diff.end());

    int ans = 0;
    for(int i = 0; i < n-k; ++i) ans += diff[i];

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}