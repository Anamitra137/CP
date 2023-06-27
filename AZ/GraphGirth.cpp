#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

vector<vector<int>> g;
vector<int> vis;

int ans = INT_MAX;

void dfs(int st,int tm){
    vis[st] = tm;
    for(int i : g[st]){
        if(vis[i]){
            if(vis[st] > vis[i]+1) ans = min(ans, vis[st] - vis[i] + 1);
        }
        else{
            dfs(i, tm+1);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    g.resize(n+1);
    vis.assign(n+1, 0);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        if(!vis[i]) dfs(i, 1);
    }

    if(ans == INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}