#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
char grid[1000][1000];
bool vis[1000][1000];

bool check(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.');
}

void dfs(int i, int j)
{
    vis[i][j] = true;
    for(int k = 0; k < 4; ++k)
    {
        int x = i + dx[k], y = j + dy[k];
        if(check(x, y) && !vis[x][y])
        {
            dfs(x, y);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            vis[i][j] = false;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == '.' && !vis[i][j])
            {
                ++cnt;
                dfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}