#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    vector<pair<int,int>> level((n+m-2)/2 + 1, {0, 0});
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int d = min(i+j, n+m-2-i-j);
            if(a[i][j]) {level[d].first++;}
            else {level[d].second++;}
        }
    }
    int num = 0;
    for(auto i : level) {
        num += min(i.first, i.second);
    }
    if((n+m) % 2 == 0) num -= min(level.back().first, level.back().second);
    cout << num << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}