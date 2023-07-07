#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int rec(int floors, int eggs, vector<vector<int>>& dp){
    if(eggs == 1){
        return floors;
    }
    if(floors <= 2 && floors >= 0){
        return floors;
    }
    if(floors < 0){
        return 1e9;
    }
    
    if(dp[floors][eggs] != -1) return dp[floors][eggs];
    
    int lo = 1, hi = floors;
    int ans = -2;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        int moves = max(rec(mid-1, eggs-1, dp), rec(floors-mid, eggs, dp));
        int movesl = max(rec(mid-2, eggs-1, dp), rec(floors-mid+1, eggs, dp));
        int movesr = max(rec(mid, eggs-1, dp), rec(floors-mid-1, eggs, dp));
        if(movesl >= moves && moves <= movesr){
            ans = 1 + moves;
            break;
        }
        else if(movesl < moves){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    
    return dp[floors][eggs] = ans;
}

int dropegg(int A, int B) {
    vector<vector<int>> dp(B+1, vector<int>(A+1, -1));
    return rec(B, A, dp);
}

void solve(){
    cout << dropegg(2, 36) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}