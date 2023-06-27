#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int h[n];
    for(int i = 0; i < n; i++) cin >> h[i];

    if(k >= n) {
        cout << abs(h[n-1] - h[0]) << endl;
        return 0;
    }

    int c[n];
    for(int i = 0; i < k; i++) c[i] = abs(h[i]-h[0]);
    for(int i = k; i < n; i++) {
        c[i] = c[i-1] + abs(h[i] - h[i-1]);
        for(int j = 2; j <= k; j++) {
            c[i] = min(c[i], c[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout << c[n-1] << endl;

    return 0;
}