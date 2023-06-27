#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
int grid[1000][1000];
int dist[1000][1000];

bool check(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(ii st){
    deque<ii> dq;
    dq.push_back(st);
    dist[st.FF][st.SS] = 0;

    while(!dq.empty()){
        ii u = dq.front(); dq.pop_front();
        int i = u.FF, j = u.SS;
        for(int k = 0; k < 4; ++k){
            int x = i + dx[k], y = j + dy[k];
            if(check(x, y)){
                if(k+1 == grid[i][j] && dist[x][y] > dist[i][j]){
                    dist[x][y] = dist[i][j];
                    dq.push_front(MP(x, y));
                }
                else if(k+1 != grid[i][j] && dist[x][y] > dist[i][j] + 1){
                    dist[x][y] = dist[i][j] + 1;
                    dq.push_back(MP(x, y));
                }
            }
        }
    }
}


void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) cin >> grid[i][j];
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) dist[i][j] = 1e9;
    }

    bfs(MP(0, 0));
    cout << dist[n-1][m-1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}