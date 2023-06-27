#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    if(s.size() == 1) {
        cout << 1 << endl;
        return;
    }

    int last1 = -1, first0 = -1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            first0 = i;
            break;
        }
    }
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '1') {
            last1 = i;
            break;
        }
    }
    if(last1 == -1 && first0 == -1) {
        cout << s.size() << endl;
        return;
    }
    if(last1 == -1) {
        cout << (first0 + 1) << endl;
        return;
    }
    if(first0 == -1) {
        cout << (s.size() - last1) << endl;
        return;
    }
    cout << (first0 - last1 + 1) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}