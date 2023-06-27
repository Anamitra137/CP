#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int rec(int i, int state, vector<vector<int>>& dp, vector<int>& a, vector<int>& next){
    int n = a.size();
    if(i == n) return 0;

    if(dp[i][state] != -1) return dp[i][state];
    
    int val = rec(i+1, 0, dp, a, next);
    if(next[i] != -1){
        if(state == 0){
            val = max(val, next[i] - i + 1 + rec(next[i], 1, dp, a, next));
        }
        else{
            val = max(val, next[i] - i + rec(next[i], 1, dp, a, next));
        }
    }

    return dp[i][state] = val;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ii> b(n);
    for(int i = 0; i < n; ++i){
        b[i].FF = a[i];
        b[i].SS = i;
    }

    sort(b.begin(), b.end());

    vector<int> next(n, -1);
    for(int i = 1; i < n; ++i){
        if(b[i-1].FF == b[i].FF){
            next[b[i-1].SS] = b[i].SS;
        }
    }

    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << rec(0, 0, dp, a, next) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}