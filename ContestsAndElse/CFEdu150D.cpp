#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

// int rec(int i, vector<ii>& a, vector<int>& dp){
//     int n = a.size();
//     if(i == n) return 0;

//     if(dp[i] != -1) return dp[i];

//     int ans = rec(i+1, a, dp);
//     for(int j = i+1; j < n; ++j){
//         if(a[i].SS >= a[j].FF){
//             ans = max(ans, rec(j+1, a, dp) + 2);
//         }
//         else{
//             break;
//         }
//     }

//     return dp[i] = ans;
// }

int dp[2000][2000][2];

int rec(int i, int j, int state, vector<ii>& a){
    int n = a.size();
    if(i >= n || j >= n) return 0;

    if(dp[i][j][state] != -1) return dp[i][j][state];

    int ans = 0;
    if(state){
        if(a[i].SS >= a[j].FF) {
            ans = rec(i, j+1, 1, a);
        }
        else{
            ans = rec(j, j+1, 0, a);
        }
    }
    else{
        ans = rec(i+1, i+2, 0, a);
        if(a[i].SS >= a[j].FF){
            int next = (a[i].SS > a[j].SS) ? i : j;
            ans = max(ans, 2 + rec(next, j+1, 1, a));
            ans = max(ans, rec(i, j+1, 0, a));
        }
    }

    return dp[i][j][state] = ans;
}

void solve(){
    int n; cin >> n;
    vector<ii> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i].FF >> a[i].SS;
    
    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    
    cout << n - rec(0, 1, 0, a) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}