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
    string s; cin >> s;

    string ans;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] != ')'){
            if(s[i] == '(') ++cnt;
            ans.push_back(s[i]);
        }
        else{
            if(cnt > 0){
                while(ans.back() != '(') ans.pop_back();
                ans.pop_back();
                --cnt;
            }
            else{
                ans.push_back(s[i]);
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}