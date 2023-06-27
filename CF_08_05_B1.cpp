#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    char s[n]; scanf("%s", s);

    char state = s[0];
    int count = 0;
    for(int i = 1; i < n; i++) {
        if(i%2 == 1 && state != s[i]) {
            count++;
            // s[i] = state;
        }
        if(i%2 == 0) {
            state = s[i];
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