#include <bits/stdc++.h>

using namespace std;

int bsearch(const vector<int>& A, int x) {
    int l = 0, h = A.size()-1;
    while(l != h) {
    int m = (l+h)/2;
    if(x <= A[m]) h = m ; 
    else l = m+1 ;
    }
    if(x <= A[l]) return l ; 
    return -2;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> sum(n);
    sum[0] = a[n-1];
    for(int i = 1; i < n; i++) {
        sum[i] = a[n-1-i] + sum[i-1];
    }
    
    for(int i = 0; i < q; i++) {
        int xj; cin >> xj;
        cout << bsearch(sum, xj) + 1 << endl;
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