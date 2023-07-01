#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int f(int t, vector<int>& a, vector<int>& p){
    int i = upper_bound(a.begin(), a.end(), t) - a.begin();
    int ans = p[i-1];
    if(i%2 == 0){
        ans += (t - a[i-1]);
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> p(n);
    p[0] = p[1] = 0;
    for(int i = 2; i < n; ++i){
        if(i%2 == 0){
            p[i] = p[i-1] + a[i] - a[i-1];
        }
        else{
            p[i] = p[i-1];
        }
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << f(r, a, p) - f(l, a, p) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}