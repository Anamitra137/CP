#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    int countneg = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] < 0) countneg++;
    }
    for(int i = 0; i < n; i++) {
        if((i < countneg && A[i] > 0) || (i >= countneg && A[i] < 0)) A[i] = -A[i];
    }
    for(int i = 0; i < n-1; i++) {
        if(A[i] > A[i+1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}