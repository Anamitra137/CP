#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0 ; i < N; i++) {
        cin >> v[i];
    }

    if(N == 1) {
        cout << "YES" << endl;
        return;
    }

    int jump2 = 0, jump3 = 0, jumpMore = 0;
    for(int i = 1; i < N; i++) {
        if(v[i] - v[i-1] == 2) jump2++;
        if(v[i] - v[i-1] == 3) jump3++;
        if(v[i] - v[i-1] > 3) jumpMore++;
    }
    
    if(jumpMore > 0) {
        cout << "NO" << endl;
        return;
    }
    if(jump3 == 1 && jump2 == 0) {
        cout << "YES" << endl;
        return;
    }
    if(jump2 <= 2 && jump3 == 0) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}