#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> A(n) , B(n), D(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    for(int i = 0; i < n; i++) cin >> D[i];

    vector<int> findInA(n+1), findInB(n+1);
    for(int i = 0; i < n; i++) findInA[A[i]] = i;
    for(int i = 0; i < n; i++) findInB[B[i]] = i;

    vector<bool> mark(n, false);
    vector<unordered_set<int>> S;
    for(int i = 0; i < n; i++) {
        
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}