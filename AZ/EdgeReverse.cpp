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
    vector<vector<ii>> g(n+1);
    for(int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        g[x].push_back(MP(y, 0));
        g[y].push_back(MP(x, 1));
    }

    vector<int> dist(n+1, 1e9);
    dist[1] = 0;
    deque<int> dq;
    dq.push_back(1);

    while(!dq.empty()){
        int u = dq.front(); dq.pop_front();

        for(ii node : g[u]){
            int v = node.FF, w = node.SS;
            if(w == 0 && dist[v] > dist[u]){
                dist[v] = dist[u];
                dq.push_front(v);
            }
            else if(w == 1 && dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                dq.push_back(v);
            }
        }
    }
    if(dist[n] == (int)1e9) cout << -1 << '\n';
    else cout << dist[n] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}