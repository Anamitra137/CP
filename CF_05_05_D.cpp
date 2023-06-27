#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if(n == 1) {
        int p;
        cin >> p;
        cout << 1 << endl;
        cout << 1 << endl;
        cout << p << endl;
        cout << endl;
        return;
    }

    vector<int> P(n+1), L, visited(n+1, 0);
    unordered_set<int> S;
    for(int i = 1; i <= n; i++) {
        cin >> P[i];
        S.insert(P[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(S.find(i) == S.end()) L.push_back(i);
    }
    vector<vector<int>> ans;
    for(int i = 0; i < L.size(); i++) {
        ans.push_back({});
        ans[i].push_back(L[i]);
        visited[L[i]] = 1;
        int j = L[i];
        while(visited[P[j]] == 0) {
            ans[i].push_back(P[j]);
            visited[P[j]] = 1;
            j = P[j];
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i.size() << endl;
        for(int j = i.size() - 1; j >= 0; j--) cout << i[j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}