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
    ll d; cin >> d;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = m-1;
    ll ans = -1;
    for(int i = n-1; i >= 0; --i){
        while(j >= 0 && b[j] > a[i] + d) --j;
        if(j >= 0){
            if(b[j] >= a[i] - d) ans = max(ans, a[i] + b[j]);
        }
        else{
            break;
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}