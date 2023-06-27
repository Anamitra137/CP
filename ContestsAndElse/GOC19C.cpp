#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

bool dp[5001][5001][2];
int ans[5001][5001];

void solve(){
    int n, m; cin >> n >> m;
    vector<int> l(n), r(n);
    for(int i = n-1; i >= 0; --i) cin >> l[i];
    for(int i = n-1; i >= 0; --i) cin >> r[i];

    for(int i = 0; i <= m ; ++i)
    {
        dp[0][i][0] = dp[0][i][1] = false;
    }
    for(int i = 0; i < n; ++i)
    {
        dp[i][0][0] = dp[i][0][1] = false;
    }

    dp[0][0][0] = true;
    dp[0][0][1] = true;

    memset(ans, -1, sizeof(ans));

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            dp[i][j][0] = dp[i][j][1] = false;
            if(j >= l[i-1])
            {
                if(dp[i-1][ j-l[i-1] ][0])
                {
                    dp[i][j][0] = true;
                    ans[i-1][j-l[i-1]] = 0;
                }
                else if(dp[i-1][ j-l[i-1] ][1])
                {
                    dp[i][j][0] = true;
                    ans[i-1][j-l[i-1]] = 0;
                }
            }

            if(j >= r[i-1])
            {
                if(dp[i-1][ j-r[i-1] ][0])
                {
                    dp[i][j][1] = true;
                    ans[i-1][j-r[i-1]] = 1;
                }
                else if(dp[i-1][ j-r[i-1] ][1])
                {
                    dp[i][j][1] = true;
                    ans[i-1][j-r[i-1]] = 1;
                }
            }
        }
    }

    // for(int i = 0; i <= n; ++i)
    // {
    //     for(int j = 0; j <= m; ++j)
    //     {
    //         cout << '(' << dp[i][j][0] << ',' << dp[i][j][1] << ") ";
    //     }
    //     cout << '\n';
    // }

    if(dp[n][m][0] || dp[n][m][1])
    {
        cout << "YES\n";
        string s(n, '0');

        int i = n, j = m;
        while(i > 0 && j > 0)
        {
            if(ans[i][j] == 0)
            {
                s[i-1] = '0';
                j -= l[i-1];
            }
            else
            {
                s[i-1] = '1';
                j -= r[i-1];
            }
            ++i;
        }
        
        cout << s << '\n';
    }
    else
    {
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}
