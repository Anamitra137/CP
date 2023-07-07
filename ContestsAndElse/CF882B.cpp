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

    int mn = a[0];
    for(int i = 1; i < n; ++i) mn &= a[i];

    if(mn > 0){
        cout << 1 << '\n';
        return;
    }

    int cnt = 0;
    int curr = a[0];
    for(int i = 1; i < n; ++i){
        if(curr == mn){
            ++cnt;
            curr = a[i];
        }
        else{
            curr &= a[i];
        }
    }
    if(curr == mn){
        ++cnt;
    }

    cout << cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}