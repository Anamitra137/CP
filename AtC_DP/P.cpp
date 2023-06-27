#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

vector<vector<int>> g;
int dp[100001][2];

int dfs(int st, int par, int col){
    if(dp[st][col] != -1) return dp[st][col];

    int ans = 1;
    for(auto i : g[st]){
        if(i != par){
            if(col){
                int comb = (dfs(i, st, 0) + dfs(i, st, 1))%MOD;
                ans = (1LL*ans*comb)%MOD;
            }
            else{
                ans = (1LL*ans*dfs(i, st, 1))%MOD;
            }
        }
    }
    return dp[st][col] = ans;
}

void solve(){
    int n; cin >> n;
    g.resize(n+1);
    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i){
        dp[i][0] = dp[i][1] = -1;
    }

    cout << (dfs(1, 0, 0) + dfs(1, 0, 1)) % MOD << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}