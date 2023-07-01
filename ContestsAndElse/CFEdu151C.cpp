#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    string s; cin >> s;
    int m; cin >> m;
    string l, r; cin >> l >> r;

    int n = s.size();

    int last = -1;
    vector<set<int>> mp(m);
    vector<vector<set<int>>> cnt(m, vector<set<int>>(10));
    for(int i = 0; i < n; ++i){
        bool flag = false;
        for(int j = 0; j <= min(m-1,last+1); ++j){
            if(l[j] <= s[i] && s[i] <= r[j]) {
                if(j > 0){
                    for(auto k : mp[j-1]){
                        cnt[j][s[i]-'0'].insert(k);
                    }
                }
                mp[j].insert(s[i]-'0');
                if(j == last+1) flag = true;
            }
        }
        if(flag) last += 1;
    }

    // for(int i = 0; i < m; ++i){
    //     for(int j = l[i]-'0'; j <= r[i]-'0'; ++j) cout << cnt[i][j] << ' ';
    //     cout << '\n';
    // }

    for(int i = 1; i < m; ++i){
        for(int j = l[i]-'0'; j <= r[i]-'0'; ++j){
            if(cnt[i][j].size() < r[i-1] - l[i-1] + 1){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}