#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    int mn = A[0];
    for(int i = 1; i < n; i++) mn = min(mn, A[i]);
    int eat = 0;
    for(int i = 0; i < n; i++) eat += A[i] - mn;
    cout << eat << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}