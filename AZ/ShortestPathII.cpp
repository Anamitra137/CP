#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

ll dist[501][501];

void solve(){
    int n, m, q; cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = 1e18;
        }
    }
    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (long long)c);
        dist[b][a] = dist[a][b];
    }

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        if(dist[a][b] == (long long)1e18) cout << -1 << '\n';
        else cout << dist[a][b] << '\n';
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