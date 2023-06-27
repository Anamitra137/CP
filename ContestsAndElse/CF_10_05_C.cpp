#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    int mn = 100000;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++){
            int sum = 0;
            for(int k = 0; k < m; k++) sum += abs(s[i][k] - s[j][k]);
            mn = min(sum, mn);
        }
    }
    cout << mn << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}