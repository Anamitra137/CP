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
    vector<int> cnt(n, 0);
    bool flag = false;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x < n) cnt[x]++;
        else flag = true;
    }

    if(flag){
        cout << "NO\n";
        return;
    }

    for(int i = 0; i < n-1; ++i){
        if(cnt[i] < cnt[i+1]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}