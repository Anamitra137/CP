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

    vector<ii> b(n);
    for(int i = 0; i < n; ++i){
        b[i] = MP(a[i], i);
    }
    sort(b.begin(), b.end());

    int k = 0;
    int last = -1;
    for(int i = 0; i < n; ++i){
        last = max(b[i].SS, last);
        if(i == last) {
            ++k;
        }
    }

    cout << k << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}