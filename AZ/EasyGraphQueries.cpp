#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

vector<vector<int>> g;
vector<int> vis;

void dfs(int st, int comp){
    vis[st] = comp;
    for(auto i: g[st]){
        if(vis[i] == 0) dfs(i, comp);
    }
}

void solve(){
    int n, m, q; cin >> n >> m >> q;
    g.resize(n+1);
    vis.resize(n+1, 0);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            ++cnt;
            dfs(i, cnt);
        }
    }

    vector<int> comps(cnt+1, 0);
    for(int i = 1; i <= n; ++i){
        comps[vis[i]]++;
    }

    while(q--){
        int type; cin >> type;
        switch(type){
            case 1:{
                int x; cin >> x;
                cout << comps[vis[x]] << '\n';
                break;
            }
            case 2:{
                int x, y; cin >> x >> y;
                if(vis[x] == vis[y]) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}