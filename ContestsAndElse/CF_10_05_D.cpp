#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int k; cin >> k;
            a[i].push_back(k);
        }
    }

    long long  mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            long long sum = a[i][j];
            int pi = i-1, pj = j-1;
            while(pi >= 0 && pj >= 0) {
                sum += a[pi][pj];
                pi--;
                pj--;
            }
            pi = i-1;
            pj = j+1;
            while(pi >= 0 && pj < m) {
                sum += a[pi][pj];
                pi--;
                pj++;
            }
            pi = i+1;
            pj = j-1;
            while(pi < n && pj >= 0) {
                sum += a[pi][pj];
                pi++;
                pj--;
            }
            pi = i+1;
            pj = j+1;
            while(pi < n && pj < m) {
                sum += a[pi][pj];
                pi++;
                pj++;
            }
            mx = max(sum, mx);
        }
    }
    cout << mx << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}