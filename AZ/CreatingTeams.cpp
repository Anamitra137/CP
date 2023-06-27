#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

vector<vector<int>> g;
vector<int> vis;
bool isbipt = true;

void dfs(int st, int col){
    vis[st] = col;
    for(auto i: g[st]){
        if(vis[i] == 0) dfs(i, 3-col);
        else if(vis[i] == col) isbipt = false;
        if(!isbipt) return;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1, 0);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        if(!vis[i]) dfs(i, 1);
    }

    if(isbipt) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}