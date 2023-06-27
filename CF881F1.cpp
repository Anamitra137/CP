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
    vector<ii> par(2);
    par[1] = MP(1, 1);
    while(n--){
        char ch; cin >> ch;
        if(ch == '+'){
            int v, x; cin >> v >> x;
            par.push_back(MP(v, x));
        }
        else{
            int u, v, k; cin >> u >> v >> k;
            if(k == 0){
                cout << "Yes\n";
                continue;
            }
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