#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void mult(vector<vector<int>>& a, vector<vector<int>>& b){
    int n = a.size();
    vector<vector<int>> mul(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            mul[i][j] = 0;
            for (int k = 0; k < n; ++k) mul[i][j] = (mul[i][j] +  (1LL*a[i][k]*b[k][j])%MOD )%MOD;
        }
    }
 
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) a[i][j] = mul[i][j];
    }
}

void power(vector<vector<int>>& F, ll n)
{
    vector<vector<int>> M = F;
 
    if (n==1) return;
 
    power(F, n/2);
    mult(F, F);
    if (n&1) mult(F, M);
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) cin >> g[i][j];
    }

    power(g, k);

    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) ans = (ans + g[i][j])%MOD;
    }
    
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}