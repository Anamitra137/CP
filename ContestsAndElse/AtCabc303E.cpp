#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int cnt = 0;

void dfs(int cen, vector<int>& vis, vector<vector<int>>& g){
    vis[cen] = cnt;
    for(int i : g[cen]){
        vis[i] = cnt;
    }

    for(int i : g[cen]){
        if(g[i].size() == 2){
            int j;
            if(g[i][0] != cen) j = g[i][0];
            else j = g[i][1];
            if(vis[j] == 0){
                ++cnt;
                int cen2;
                if(g[j][0] != i) cen2 = g[j][0];
                else cen2 = g[j][1];

                dfs(cen2, vis, g);
            }
        }
    }

}

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    vector<int> deg(n+1, 0);
    vector<int> vis(n+1, 0);
    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(deg[i] == 1 && vis[i] == 0){
            ++cnt;
            int st = g[i][0];
            dfs(st, vis, g);
            break;
        }
    }


    vector<int> cmp(cnt+1, 0);
    for(int i = 1; i <= n; ++i){
        cmp[vis[i]]++;
    }

    sort(cmp.begin()+1, cmp.end());

    for(int i = 1; i <= cnt; ++i) cout << cmp[i]-1 << ' ';
    cout << '\n';
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}