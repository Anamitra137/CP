#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count = 0;
    for(int i = n-2; i >= 0; i--) {
        if(A[i+1] == 0) {
            cout << -1 << endl;
            return;
        }

        if(A[i] > A[i+1]) {
            int k = ceil(log2(double(A[i]) / A[i+1]));
            long long pow2 = 1<<k;
            A[i] /= pow2;
            count += k;
        }
        if(A[i] == A[i+1]) {
            A[i] /= 2;
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}