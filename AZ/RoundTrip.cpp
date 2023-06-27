#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

vector<vector<int>> g;
vector<bool> vis;
bool cycle = false;

void dfs(int st, int par){
    vis[st] = true;
    for(auto i: g[st]){
        if(!vis[i]){
            dfs(i, st);
        }
        else if(i != par){
            cycle = true;
        }
        if(cycle) return; 
    }
}

void solve(){
    int n, m; cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1, false);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i]) dfs(i, 0);
    }

    if(cycle) cout << "YES\n";
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