#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    char s[n+1];
    cin >> s;

    if(k >= 25) {
        for(int i = 0; i < n; i++) cout << 'a';
        cout << endl;
        return;
    }

    unordered_map<char, char> update;
    for(char i = 'a'; i <= 'z'; i++) {
        update.insert({i, i});
    }
    long long cost = k;
    int ind1 = n, ind2 = n;
    for(int i = 0; i < n; i++) {
        if(s[i] - 'a' > k) {
            ind2 = i;
            break;
        }
    }
    int mx = 0;
    for(int i = 0; i < ind2; i++) {
        if(s[i] - 'a' <= k && mx < s[i] - 'a') {
            mx = s[i] - 'a';
            ind1 = i;
        }
    }

    if(ind1 != n ) { // ind1 job
        cost = cost - (s[ind1] - 'a');
        for(char j = s[ind1]; j >= 'a'; j--) update[j] = 'a';
    }
    if(cost > 0 && ind2 != n) { // ind2 job
        for(char j = s[ind2]; j >= s[ind2] - cost; j--) update[j] = s[ind2] - cost;
        cost = 0;
    }
    
    for(int i = 0; i < n; i++) s[i] = update[s[i]];

    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}