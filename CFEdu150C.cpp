#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int n;
string s;
int dp[200000][5][2];   // INT_MIN for unprocessed INT_MAX for invalid
int val[] = {1, 10, 100, 1000, 10000};

int rec(int i, int j, int flag){
    int curr = s[i]-'A';
    if(i == n-1){
        if((j == curr && !flag) || (j != curr && flag)){
            return val[j];
        }
        else{
            return INT_MAX;
        }
    }

    if(dp[i][j][flag] > INT_MIN) return dp[i][j][flag];

    int last;
    for(last = 0; last < 5; ++last){
        if(rec(i+1, last, 0) < INT_MAX) break;
    }

    int ans = INT_MIN;
    if(!flag){
        if(curr >= last && j == curr){
            ans = rec(i+1, last, 0) + val[curr];
        }
        else if(curr < last && j == last){
            ans = rec(i+1, last, 0) - val[curr];
        }
    }
    else{
        if(j >= last && j != curr) ans = rec(i+1, last, 0) + val[j];

        if(curr == j){
            for(int k = 0; k <= curr; ++k){
                if(rec(i+1, k, 1) < INT_MAX) ans = max(ans, rec(i+1, k, 1) + val[curr]);
            }
        }
        else if(curr < j && rec(i+1, j, 1) < INT_MAX){
            ans = max(ans, rec(i+1, j, 1) - val[curr]);
        }
    }
    if(ans == INT_MIN) ans = INT_MAX;
    return dp[i][j][flag] = ans;
}

void solve(){
    cin >> s;
    n = s.size();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 5; ++j){
            dp[i][j][0] = dp[i][j][1] = INT_MIN;
        }
    }

    int ans = INT_MIN;
    for(int j = 0; j < 5; ++j){
        if(rec(0, j, 0) < INT_MAX) ans = max(ans, rec(0, j, 0));
        if(rec(0, j, 1) < INT_MAX) ans = max(ans, rec(0, j, 1));
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}