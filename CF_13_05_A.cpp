#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    if(r1 < l2 || r2 < l1) cout << (l1 + l2) << endl;
    else if(l1 <= l2 && l2 <= r1) cout << l2 << endl;
    //else if(l2 <= l1 && l1 <= r2) cout << l1 << endl;
    else cout << l1 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}