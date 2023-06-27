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
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    ll sum = 0;
    for(int i = 0; i < n; ++i) sum += abs(a[i]);

    int cnt = 0;
    bool flag = false;
    for(int i = 0; i < n; ++i){
        if(!flag && a[i] < 0){
            flag = true;
            ++cnt;
        }
        else if(a[i] > 0){
            flag = false;
        }
    }

    cout << sum << ' ' << cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}