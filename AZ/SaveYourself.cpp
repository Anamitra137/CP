#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;
char grid[1000][1000];

bool check(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#');
}

void bfs(vector<ii>& st, vector<vector<int>>& dist){
    queue<ii> q;
    for(auto i : st) q.push(i);

    while(!q.empty()){
        ii node = q.front(); q.pop();
        int i = node.FF, j = node.SS;
        
        for(int k = 0; k < 4; ++k){
            int x = i + dx[k], y = j + dy[k];
            if(check(x, y) && dist[x][y] > dist[i][j] + 1){
                dist[x][y] = dist[i][j] + 1;
                q.push(MP(x, y));
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    vector<ii> stA, stM;
    vector<vector<int>> distA(n, vector<int>(m, 1e9)),  distM(n, vector<int>(m, 1e9));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                stA.push_back(MP(i, j));
                distA[i][j] = 0;
            }
            else if(grid[i][j] == 'M') {
                stM.push_back(MP(i, j));
                distM[i][j] = 0;
            }
        }
    }

    bfs(stA, distA);
    bfs(stM, distM);

    int ans = 1e9;

    for(int i = 0; i < n; ++i){
        if(grid[i][0] != '#' && distA[i][0] < distM[i][0]){
            ans = min(ans, distA[i][0]);
        }
        if(grid[i][m-1] != '#' && distA[i][m-1] < distM[i][m-1]){
            ans = min(ans, distA[i][m-1]);
        }
    }
    for(int j = 0; j < m; ++j){
        if(grid[0][j] != '#' && distA[0][j] < distM[0][j]){
            ans = min(ans, distA[0][j]);
        }
        if(grid[n-1][j] != '#' && distA[n-1][j] < distM[n-1][j]){
            ans = min(ans, distA[n-1][j]);
        }
    }

    if(ans == (int)1e9) cout << "NO\n";
    else{
        cout << "YES\n" << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}