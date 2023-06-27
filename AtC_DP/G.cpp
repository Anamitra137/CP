#include <bits/stdc++.h>

using namespace std;

void myDFS(const vector<vector<int>>& G, int u, vector<int>& path) {
    //if(path[u] != -1) return;
    if(G[u].size() == 0) {path[u] = 0; return;}
    int mx = 0;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(path[v] == -1) myDFS(G, v, path);
        mx = max(mx, path[v]);
    }
    path[u] = mx + 1;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        G[x-1].push_back(y-1);
    }

    vector<int> path(n, -1);
    for(int i = 0; i < n; i++) {
        if(path[i] == -1) myDFS(G, i, path);
    }

    int mx = 0;
    for(int i = 0; i < n; i++) mx = max(mx, path[i]);
    cout << mx << endl;

    return 0;
}