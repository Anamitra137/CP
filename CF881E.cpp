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
    vector<ii> lr(m);
    for(int i = 0; i < m; ++i) cin >> lr[i].FF >> lr[i].SS;

    int q; cin >> q;
    vector<int> x(q+1);
    for(int i = 1; i <= q; ++i) cin >> x[i];

    int lo = 1, hi = q;
    int ans = -1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        vector<int> a(n+1, 0);
        for(int i = 1; i <= mid; ++i) a[x[i]]++;
        for(int i = 2; i <= n; ++i) a[i] += a[i-1];
        bool flag = false;
        for(auto i : lr){
            int cnt = a[i.SS] - a[i.FF-1];
            if(2*cnt > i.SS - i.FF + 1){
                flag = true;
                break;
            }
        }

        if(flag){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

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