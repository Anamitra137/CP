#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> ans(n);
    int idx = n - n/2 -1 ;
    ans[0] = a[idx];
    for(int i = 1, j = idx + 1; i < n; i += 2, ++j){
        ans[i] = a[j];
    }
    for(int i = 2, j = 0; i < n; i += 2, ++j){
        ans[i] = a[j];
    }

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