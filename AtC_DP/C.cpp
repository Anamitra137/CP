#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int h[n][3];
    h[0][0] = a[0]; h[0][1] = b[0]; h[0][2] = c[0];
    for(int i = 1; i < n; i++) {
        h[i][0] = a[i] + max(h[i-1][1], h[i-1][2]);
        h[i][1] = b[i] + max(h[i-1][0], h[i-1][2]);
        h[i][2] = c[i] + max(h[i-1][0], h[i-1][1]);
    }
    cout << max(h[n-1][0], max(h[n-1][1], h[n-1][2]));

    return 0;
}