#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int myDFS(vector<vector<int>>& a, vector<vector<bool>>& v, int i, int j)
{
    int n = a.size(), m = a[0].size();
    if(i < 0 || i >= n || j < 0 || j >= m || v[i][j] || a[i][j] == 0) return 0;
    v[i][j] = true;
    int vol = a[i][j];
    for(int k = 0; k < 4; ++k)
    {
        vol += myDFS(a, v, i+dx[k], j+dy[k]);
    }
    return vol;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<bool>> v(n, vector<bool>(m, false));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];

    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(v[i][j]) continue;
            int vol = myDFS(a, v, i, j);
            mx = max(mx, vol);
        }
    }
    cout << mx << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}