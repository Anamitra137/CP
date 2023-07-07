#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

class Dsu{
    int setsize, n;
    int *par, *rank;

    public:
    Dsu(int sz = 0)
    : n{sz}, setsize{sz}, par{new int[sz+1]}, rank{new int[sz+1]}
    {
        for(int i = 1; i <= n; ++i){
            par[i] = i;
            rank[i] = 1;
        }
    }
    ~Dsu(){
        delete[] par;
        delete[] rank;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        int xp = find(x), yp = find(y);
        if(xp != yp){
            if(rank[xp] < rank[yp]) swap(xp, yp);
            par[yp] = xp;
            rank[xp] += rank[yp];
            --setsize;
        }
    }

    int size() { return setsize; }

    void reset(){
        setsize = n;
        for(int i = 1; i <= n; ++i){
            par[i] = i;
            rank[i] = 1;
        }
    }
};

void solve(){
    int n, m; cin >> n >> m;
    Dsu s(n);
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        s.merge(u, v);
    }

    int k; cin >> k;
    set<ii> a;
    for(int i = 0; i < k; ++i){
        int u, v; cin >> u >> v;
        u = s.find(u), v = s.find(v);
        ii p = (u <= v) ? MP(u, v) : MP(v, u);
        a.insert(p);
    }

    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        u = s.find(u), v = s.find(v);
        if(u != v){
            ii p = (u <= v) ? MP(u, v) : MP(v, u);
            if(a.find(p) != a.end()){
                cout << "No\n";
                continue;
            }
        }
        cout << "Yes\n";
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