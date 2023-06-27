#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Dsu {
    private:
    int *parent, *rank;

    public:
    Dsu(std::size_t n) {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~Dsu() {
        delete[] parent;
        delete[] rank;
    }

    int find(int x) { // find with path compression
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    int join(int x, int y) { // Union by rank
        int xp = find(x), yp = find(y);
        if(xp == yp) return xp;
        if(rank[xp] < rank[yp]) swap(xp, yp);
        parent[yp] = xp;
        if(rank[xp] == rank[yp]) rank[xp]++;
        return xp;
    }
};

struct Edge{
    int src, des, wt;

    Edge(int u, int v, int w)
    : src{u}, des{v}, wt{w}
    {}
};


// Kruskal's algorithm for MST in a weighted undirected connected graph
// O(mlogm) for sorting + O(n-1) = O(mlogm), clearly m >= n-1

int main() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }

    auto compare = [](Edge a, Edge b) {return (a.wt < b.wt);};
    sort(edges.begin(), edges.end(), compare);

    int cost = 0, cnt = 0;
    Dsu S(n);
    for(int i = 0; cnt <= n-1 && i < m; i++) {
        int u = edges[i].src;
        int v = edges[i].des;
        if(S.find(u) != S.find(v)) {
            cost += edges[i].wt;
            S.join(u, v);
            cnt++;
        }
    }
    cout << cost << endl;

    return 0;
}