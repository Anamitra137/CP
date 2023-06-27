#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void dfs(int st, int par, vector<char>& ch, vector<vector<int>>& g, vector<vector<int>>& sub){
    sub[st][ch[st]-'a']++;
    for(int i : g[st]){
        if(i != par){
            dfs(i, st, ch, g, sub);
            for(int j = 0; j < 26; ++j){
                sub[st][j] += sub[i][j];
            }
        }
    }
}

void solve(){
    int n, q; cin >> n >> q;
    vector<char> ch(n+1);
    for(int i = 1; i <= n; ++i) cin >> ch[i];
    vector<vector<int>> g(n+1);
    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> sub(n+1, vector<int>(26, 0));
    dfs(1, 0, ch, g, sub);

    while(q--){
        int m; cin >> m;
        string s; cin >> s;
        int cnt[26]{0};
        for(char i : s){
            cnt[i-'a']++;
        }

        int ans = 0;
        for(int i = 0; i < 26; ++i){
            ans += max(0, cnt[i] - sub[m][i]);
        }

        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}