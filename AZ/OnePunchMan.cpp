#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1, 0};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1, 0};

int h, w;
char grid[1000][1000];
int dist[1000][1000];

bool check(int i, int j){
    return (i >= 0 && i < h && j >= 0 && j < w);
}

void solve(){
    cin >> h >> w;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            dist[i][j] = 1e9;
        }
    }

    dist[0][0] = 0;
    deque<ii> dq;
    dq.push_back(MP(0, 0));

    while(!dq.empty()){
        ii u = dq.front(); dq.pop_front();
        int i = u.FF, j = u.SS;
        for(int k = 0; k < 4; ++k){
            int x = i + dx[k], y = j +dy[k];
            if(check(x, y)){
                if(grid[x][y] == '.' && dist[x][y] > dist[i][j]){
                    dist[x][y] = dist[i][j];
                    dq.push_front(MP(x, y));
                }
                else if(grid[x][y] == '#'){
                    for(int a = 0; a < 9; ++a){
                        int xx = x + dx[a], yy = y + dy[a];
                        if(check(xx, yy) && dist[xx][yy] > dist[i][j] + 1){
                            dist[xx][yy] = dist[i][j] + 1;
                            dq.push_back(MP(xx, yy));
                        }
                    }
                }
            }
        }
    }

    cout << dist[h-1][w-1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}