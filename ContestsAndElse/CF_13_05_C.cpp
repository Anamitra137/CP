#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int c0 = 0, c1 = 0;
    for(auto i : s) {
        if(i == '0') c0++;
    }

    int l = 0, r = s.size()-1;
    int mn = max(c1, c0);
    while(l < r) {
        int lc1 = 0, lc0 = 0;
        for(int i = l; i <= r; i++) {
            if(s[l] == '0') {
                c0--;
                l++;
                continue;
            }
            if(s[i] == '1') lc1++;
            else lc0++;
            if(lc1 == lc0) break;
        }
        int rc1 = 0, rc0 = 0;
        for(int i = r; i >= l; i--) {
            if(s[r] == '0') {
                c0--;
                r--;
                continue;
            }
            if(s[i] == '1') rc1++;
            else rc0++;
            if(rc1 == rc0) break;
        }
        if(lc0 > rc0 ) {
            l += 2*lc0;
            c1 += lc0;
            c0 -= lc0;
        }
    }
    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] == '0') c0--;
        if(s[i] == '1' && s[i+1] == '0') {
            c1++;
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