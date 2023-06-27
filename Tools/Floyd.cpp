// Floyd-Warshall algorithm for all pair shortest path
// in a weighted DIRECTED/UNDIRECTED graph
// O(n^3)


#include <bits/stdc++.h>

using namespace std;

int dist[400][400];
int par[400][400];

void printpath(int i, int j){
    if(i != j) printpath(i, par[i][j]);
    cout << j << ' ';
}

void solve(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j) dist[i][j] = 1e9;
            par[i][j] = i;
        }
    }
    for(int i = 0; i < n; i++) dist[i][i] = 0;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}