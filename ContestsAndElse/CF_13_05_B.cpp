#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> A(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch; cin >> ch;
            A[i].push_back(ch);
        }
    }

    int ind1 = 6, jnd1 = 6, ind2 = 6, jnd2 = 6;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 'R') {
                if(i < ind1) {ind1 = i; jnd1 = j;}
                if(j < jnd2) {jnd2 = j; ind2 = i;}
            }
        }
    }
    if(ind1 == ind2 || jnd1 == jnd2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}