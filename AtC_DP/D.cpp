#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, W; cin >> n >> W;
    long long w[n], v[n];
    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<long long> curr(W+1, 0), next(W+1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= W; j++) {
            if(j >= w[i]) next[j] = max(curr[j], curr[j-w[i]] + v[i]);
            else next[j] = curr[j];
        }
        curr = next;
    }
    cout << curr[W] << endl;

    return 0;
}