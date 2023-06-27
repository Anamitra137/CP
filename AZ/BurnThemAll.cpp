#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n+1);
    vector<pair<ii, ll>> edges(m);
    for(int i = 0; i < m; ++i){
        int u, v, d; cin >> u >> v >> d;
        g[u].push_back(MP(v, d));
        g[v].push_back(MP(u, d));

        edges[i] = MP(MP(u, v), d);
    }

    int st; cin >> st;

    vector<ll> dist(n+1, 1e18);
    vector<bool> vis(n+1, false);

    priority_queue<pair<ll, int>> pq;
    pq.push(MP(0, st));
    dist[st] = 0;

    while(!pq.empty()){
        int u = pq.top().SS; pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto p : g[u]){
            int v = p.FF;
            ll wt = p.SS;
            if(dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push(MP(-dist[v], v));
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < m; ++i){
        int u = edges[i].FF.FF, v = edges[i].FF.SS;
        ll d = edges[i].SS;
        ans = max(ans, 5*(dist[u] + dist[v] + d));
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