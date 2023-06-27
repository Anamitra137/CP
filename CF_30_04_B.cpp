#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> A(26, 0);
    for(int i = 0; i < s.size(); i++) {
        A[s[i] - 'a']++;
    }

    int count = 0;
    for(int i = 0; i < 26; i++) {
        if(A[i] > 0) count++;
    }

    for(int i = 0; i < s.size() - count; i++) {
        if(s[i] != s[i + count]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}