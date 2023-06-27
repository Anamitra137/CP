#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int dist[501][501];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> dist[i][j];
        }
    }

    vector<int> x(n), ans(n);
    for(int i = 0; i < n; ++i) cin >> x[i];

    for(int k = n-1; k >= 0; --k){
        ll sum = 0;
        for(int i = n-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                int a = x[i], b = x[j], c = x[k];
                dist[a][b] = min(dist[a][b], dist[a][c] + dist[c][b]);
                if(i >= k && j >= k) sum += dist[a][b];
            }
        }
        ans[k] = sum;
    }
    
    for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
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