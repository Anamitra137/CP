#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int src, des, wt;

    Edge(int u, int v, int w) 
    : src{u}, des{v}, wt{w}
    {}
};

// BellmanFord algorithm for shortest path tree from source vertex
// in a DIRECTED graph where edges may have negative weights
// reports single source shortest paths or a negative cycle
// O(mn)

int main() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }

    vector<int> d(n, INT_MAX), p(n, -1);
    int u = 0; // source node
    d[u] = 0;
    bool flag;
    for(int cnt = 0; cnt < n; cnt++) { // The nth time is for negative cycle detection
        flag = false;
        for(int i = 0; i < m; i++) {
            int u = edges[i].src;
            int v = edges[i].des;
            int w = edges[i].wt;
            if(d[u] < INT_MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
                flag = true;
            }
        }
    }
    if(flag) { // if we have a relaxation even in the nth step then negative cycle
        cout << "Negative cycle exists" << endl;
    }
    else {
        for(int i = 0; i < n; i++) cout << d[i] << ' ';
        cout << endl;
    }

    return 0;
}