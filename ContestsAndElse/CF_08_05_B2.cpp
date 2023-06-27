#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    char s[n]; scanf("%s", s);

    int count = 0;
    for(int i = 1; i < n; i += 2) {
        if(s[i-1] != s[i]) count++;
        else break;
    }
    if(2*count == n) {
        cout << count << " " << 1 << endl;
        return;
    }
    char state = s[2*count];
    for(int i = 0; i < 2*count; i++) s[i] = state;
    for(int i = 2*count + 2; i < n; i++) {
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