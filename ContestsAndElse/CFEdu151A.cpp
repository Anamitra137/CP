#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n, k, x; cin >> n >> k >> x;

    if(x != 1) {
        cout << "YES\n";
        cout << n << '\n';
        for(int i = 1; i <= n; ++i) cout << 1 << ' ';
        cout << '\n';
    }
    else{
        if(n%2 == 0 && k >= 2){
            cout << "YES\n";
            cout << n/2 << '\n';
            for(int i = 1; i <= n/2; ++i) cout << 2 << ' ';
            cout << '\n';
        }
        else if(n%2 == 1 && k >= 3){
            cout << "YES\n";
            cout << n/2 << '\n';
            for(int i = 1; i < n/2; ++i) cout << 2 << ' ';
            cout << 3 << '\n';
        }
        else{
            cout << "NO\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}