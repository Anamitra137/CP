// O((V+E)logE)
// Fails if negative cycle

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

vector<vector<ii>> g;
vector<int> vis;
vector<ll> dist;

void dijkstra(int src){
    dist[src] = 0;
    priority_queue<ii> pq;
    pq.push(MP(0, src));

    while(!pq.empty()){
        int u = pq.top().S; pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        for(ii p : g[u]){
            int v = p.F, w = p.S;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(MP(-dist[v], v));
            }
        }
    }
}

void solve(){
    g.clear(); vis.clear(); dist.clear();
    int n, m; cin >> n >> m;
    g.resize(n+1); vis.assign(n+1, 0); dist.assign(n+1, 1e18);
    for(int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(MP(v, w));
        g[v].push_back(MP(u, w));
    }

    dijkstra(1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}