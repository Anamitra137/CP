#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void myDFS(vector<vector<pair<int,int>>>& G, int st, int p, int par, int r, vector<int>& read)
{
    for(auto i : G[st])
    {
        if(i.first == p) continue;

        if(par == -1) read[i.second] = 1;
        else if(i.second < par) read[i.second] = r+1;
        else read[i.second] = r;

        myDFS(G, i.first, st, i.second, read[i.second], read);
    }
}


void solve(){
    int n; cin >> n;

    vector<vector<pair<int,int>>> G(n);

    vector<pair<int,int>> edges(n-1);
    for(int i = 0; i < n-1; ++i)
    {
        int x, y; cin >> x >> y;
        --x; --y;
        if(x > y) swap(x, y);
        edges[i] = {x, y};

        G[x].push_back({y, i});
        G[y].push_back({x, i});
    }

    vector<int> p(n-1, -1);
    vector<int> readings(n-1, -1);
    myDFS(G, 0, -1, -1, 0, readings);

    // for(int i = 0; i < n-1; ++i)
    // {
    //     cout << p[i] << ' ';
    // }
    // cout << '\n';

    int ans = 0;
    for(int i = 0; i < n-1; ++i)
    {
        ans = max(ans, readings[i]);
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}