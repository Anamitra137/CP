#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

// int dp[100001];
// vector<int> a;

// bool rec(int k){
//     if(dp[k] != -1) return dp[k];

//     for(auto i: a){
//         if(i == k) return (dp[k] = 1);
//         if(k > i && !rec(k-i)) return (dp[k] = 1);
//     }
//     return (dp[k] = 0);
// }

// void solve(){
//     int n, k; cin >> n >> k;
//     a.resize(n);
//     for(int i = 0; i < n; ++i) cin >> a[i];
//     for(int i = 0; i <= k; ++i) dp[i] = -1;

//     if(rec(k)) cout << "First\n";
//     else cout << "Second\n";
// }

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    vector<bool> dp(k+1);
    dp[0] = false;
    for(int i = 1; i <= k; ++i){
        dp[i] = false;
        for(auto val: a){
            if(i >= val && !dp[i-val]){
                dp[i] = true;
                break;
            }
        }
    }

    if(dp[k]) cout << "First\n";
    else cout << "Second\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}