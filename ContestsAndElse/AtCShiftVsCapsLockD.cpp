#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

ll dp[300010][2];
int x, y, z;

ll rec(int i, int on, string& s){
    if(i == s.size()){
        return 0;
    }

    if(dp[i][on] != -1) return dp[i][on];

    ll ans = 0;
    if((s[i] == 'a' && !on) || (s[i] == 'A' && on)){
        ans = min(x + rec(i+1, on, s), z + y + rec(i+1, 1-on, s));
    }
    else{
        ans = min(y + rec(i+1, on, s), z + x + rec(i+1, 1-on, s));
    }

    return dp[i][on] = ans;
}

void solve(){
    cin >> x >> y >> z;
    string s; cin >> s;

    for(int i = 0; i <= s.size(); ++i){
        dp[i][0] = dp[i][1] = -1;
    }

    cout << rec(0, 0, s) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}