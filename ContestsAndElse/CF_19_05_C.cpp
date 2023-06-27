#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), s(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    s = a;
    for(int i = 0; i < n; i++) {
       sort(s[i].begin(), s[i].end());
    }


    vector<int> p;
    int col1 = -1, col2 = -1;
    for(int i = 0; i < n; i++) {
        int count = 0, j1, j2;
        for(int j = 0; j < m; j++) {
            if(a[i][j] != s[i][j]) {
                count++;
                if(count == 1) j1 = j;
                if(count == 2) j2 = j;
                if(count > 2) {cout << -1 << endl; return;}
            }
        }
        if(count == 0) {p.push_back(i); continue;}
        if(col1 == -1) {
            col1 = j1; col2 = j2;
            continue;
        }
        if(col1 != j1 || col2 != j2) {cout << -1 << endl; return;}
    }
    if(col1 == -1) {cout << 1 << " " << 1 << endl; return;}

    for(int i = 0; i < p.size(); i++) {
        int ind = p[i];
        if(a[ind][col1] != a[ind][col2]) {cout << -1 << endl; return;}
    }

    cout << (col1+1) << " " << (col2+1) << endl;
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