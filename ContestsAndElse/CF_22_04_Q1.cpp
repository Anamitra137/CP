#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int size = s.size();
    if(size == 1) {
        cout << "NO" << endl;
        return;
    }
    if(s[0] != s[1] || s[size - 1] != s[size - 2]) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 1; i <= size-2; i++) {
        if(s[i-1] != s[i] && s[i] != s[i+1]) {
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