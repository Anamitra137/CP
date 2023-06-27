#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    sort(A.begin(), A.end());

    int count = 0, op = 0;
    if(A[0] == 0) {count++;}
    for(int i = 1; i < n; i++) {
        if(A[i-1] == A[i] && A[i] != 0) {
            A[i-1] = 0;
            count++;
            op++;
        }
        if(A[i] == 0) {
            count++;
        }
    }
    if(count == 0) {
        cout << (n+1) << endl;
    }
    else {
        cout << (n-count+op) << endl;
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