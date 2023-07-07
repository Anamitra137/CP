#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    string s[3];
    cin >> s[0] >> s[1] >> s[2];

    for(int i = 0; i < 3; ++i){
        if(s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][0] != '.'){
            cout << s[i][0] << '\n';
            return;
        }
    }
    for(int i = 0; i < 3; ++i){
        if(s[0][i] == s[1][i] && s[1][i] == s[2][i] && s[0][i] != '.'){
            cout << s[0][i] << '\n';
            return;
        }
    }
    if(s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[0][0] != '.'){
        cout << s[0][0] << '\n';
        return;
    }
    if(s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[0][2] != '.'){
        cout << s[0][2] << '\n';
        return;
    }
    cout << "DRAW\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}