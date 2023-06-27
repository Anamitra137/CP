#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void bfs(int st, vector<vector<int>>& g, vector<int>& dist){
    queue<int> q;
    dist[st] = 0;
    q.push(st);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    for(int i = 0; i < n-1; ++i){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist(n+1, 1e9);

    bfs(1, g, dist);
    int node = 1, mx = 0;
    for(int i = 1; i <= n; ++i){
        if(mx < dist[i]){
            node = i;
            mx = dist[i];
        }
    }

    dist.assign(n+1, 1e9);
    bfs(node, g, dist);
    mx = 0;
    for(int i = 1; i <= n; ++i){
        mx = max(mx, dist[i]);
    }

    cout << mx << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}