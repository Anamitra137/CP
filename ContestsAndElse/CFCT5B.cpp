#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

bool check(int val, int x){
    return (((~x)&val) == 0);
}

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    for(int i = 0; i < n; ++i) cin >> c[i];

    int curr = 0;
    for(int i = 0; i < n; ++i){
        if(check((curr|a[i]), x)) curr |= a[i];
        else break;
    }
    for(int i = 0; i < n; ++i){
        if(check((curr|b[i]), x)) curr |= b[i];
        else break;
    }
    for(int i = 0; i < n; ++i){
        if(check((curr|c[i]), x)) curr |= c[i];
        else break;
    }

    if(curr == x){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
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