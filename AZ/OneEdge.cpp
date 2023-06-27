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
    int n, m; cin >> n >> m;
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

    long long sum = 0, sqsum = 0;
    for(int i = 1; i <= cnt; ++i){
        sum += comps[i];
        sqsum += 1LL*comps[i]*comps[i];
    }

    cout << (sum*sum - sqsum)/2 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}