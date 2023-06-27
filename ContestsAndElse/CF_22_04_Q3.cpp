#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long N, x;
    cin >> N >> x;
    vector<long long> v(N);
    for(long long i = 0 ; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long cash = x;
    long long number = 0;
    for(long long i = 0; i < N && (cash - v[i]) >= 0; i++) {
        number += (cash - v[i]) / (i+1) + 1;
        cash -= v[i];
    }

    cout << number << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}