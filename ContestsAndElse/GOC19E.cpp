#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

int LPS(string& s, char ch)
{
    int n = s.size();

    int st = -1, sp = -1;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == ch)
        {
            st = i;
            break;
        }
    }
    if(st == -1)
    {
        return 0;
    }
    for(int i = n-1; i >= 0; --i)
    {
        if(s[i] == ch)
        {
            sp = i;
            break;
        }
    }
    if(sp <= st+2)
    {
        return (sp-st+1);
    }

    int m = sp-st-1;

    vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
    for(int i = 1; i <= m; ++i)
    {
        for(int j = m-1; j >= 0; --j)
        {
            if(s[i+st] == s[j+st+1])
            {
                dp[i][j] = 1 + dp[i-1][j+1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
            }
        }
    }

    return 2+dp[m][0];
}

void solve(){
    string s; cin >> s;

    cout << LPS(s, 'A') << ' ' << LPS(s, 'G') << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}