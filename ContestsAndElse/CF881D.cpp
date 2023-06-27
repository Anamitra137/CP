#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int dfs(vector<vector<int>>& g, int st, int par, vector<int>& l){
    int cnt = 0;
    for(auto i : g[st]){
        if(i != par) cnt += dfs(g, i, st, l);
    }
    if(cnt == 0) cnt = 1;
    return (l[st] = cnt);
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> l(n+1, 0);
    dfs(g, 1, 0, l);

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        cout << (1LL*l[x]*l[y]) << '\n';
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