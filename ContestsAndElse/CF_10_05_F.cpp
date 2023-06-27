#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ind1, ind2;
    int val = a[0], count = 1;
    for(int i = 1; i < n; i++) {
        if(val != a[i]) {
            if(count >= k) {

            }
        }
        else {
            count++;
        }
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