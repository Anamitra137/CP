#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int n, m;
vector<vector<ii>> g;

ll mst(int st){
    vector<bool> vis(n+1, false);
    priority_queue<ii> pq;
    int cnt = 0;
    ll ans = 0;
    pq.push(MP(0, st));
    while(!pq.empty()){
        ii vals = pq.top(); pq.pop();
        int u = vals.SS;
        int wt = -vals.FF;
        if(vis[u]) continue;
        vis[u] = true;
        ans += wt;
        ++cnt;
        for(auto p : g[u]){
            int v = p.FF, w = p.SS;
            if(!vis[v]){
                pq.push(MP(-w, v));
            }
        }
    }
    if(cnt == n) return ans;
    else return -1;
}

void solve(){
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(MP(b, c));
        g[b].push_back(MP(a, c));
    }

    ll ans = mst(1);
    if(ans == -1) cout << "IMPOSSIBLE\n";
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


