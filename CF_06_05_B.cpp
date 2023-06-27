#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    char s[n+1]; scanf("%s", s);
    int k; cin >> k;
    unordered_set<char> C;
    for(int i = 0; i < k; i++) {char ch; cin >> ch; C.insert(ch);}

    int ind = -1;
    for(int i = n-1; i >= 0; i--) {
        if(C.find(s[i]) != C.end()) {
            ind = i;
            break;
        }
    }
    if(ind <= 0) {
        cout << 0 << endl;
        return;
    }

    int count = 0, mx = 0;
    for(int i = ind-1; i >= 0; i--) {
        if(C.find(s[i]) != C.end()) {
            mx = max(mx, count + 1);
            count = 0;
        }
        else {
            count++;
        }
    }
    mx = max(mx, count);
    cout << mx << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}