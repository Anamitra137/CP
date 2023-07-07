#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;


void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> p(k+1), h(k+1);
    for(int i = 1; i <= k; ++i){
        cin >> p[i] >> h[i];
    }

    priority_queue<ii> pq;
    vector<bool> vis(n+1, false);
    for(int i = 1; i <= k; ++i){
        pq.push(MP(h[i], p[i]));
    }

    while(!pq.empty()){
        ii top = pq.top(); pq.pop();
        int u = top.SS;
        int d = top.FF;

        if(vis[u]) continue;
        vis[u] = true;

        if(d > 0){
            for(int v : g[u]){
                pq.push(MP(d-1, v));
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(vis[i]) ++cnt;
    }
    cout << cnt << '\n';
    for(int i = 1; i <= n; ++i){
        if(vis[i]) cout << i << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}