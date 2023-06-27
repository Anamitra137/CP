#include<bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n;
char grid[1000][1000];
int vis[1000][1000][2];

bool check(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == '#');
}

void dfs(int i, int j, int comp)
{
    vis[i][j][0] = comp;
    int cnt = 0;
    for(int k = 0; k < 4; ++k)
    {
        int x = i + dx[k], y = j + dy[k];
        if(check(x, y))
        {
            ++cnt;
            if(!vis[x][y][0]) dfs(x, y, comp);
        }
    }
    vis[i][j][1] = 4-cnt;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            vis[i][j][0] = 0;
        }
    }

    int cntComp = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] == '#' && !vis[i][j][0])
            {
                ++cntComp;
                dfs(i, j, cntComp);
            }
        }
    }
    
    vector<pair<int, int>> areaperi(cntComp, make_pair(0, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] == '#'){
                areaperi[vis[i][j][0]-1].first++;
                areaperi[vis[i][j][0]-1].second += vis[i][j][1];
            }
        }
    }

    int mx = 0, mn = INT_MAX;
    for(int i = 0; i < cntComp; ++i)
    {
        if(mx < areaperi[i].first)
        {
            mx = areaperi[i].first;
            mn = areaperi[i].second;
        }
        else if(mx == areaperi[i].first)
        {
            mn = min(mn, areaperi[i].second);
        }
    }

    cout << mx << ' ' << mn << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}