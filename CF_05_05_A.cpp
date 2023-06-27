#include <iostream>

using namespace std;

void solve() {
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long dog = x - a, cat = y - b;
    if(dog <= 0) dog = 0;
    if(cat <= 0) cat = 0;

    if(dog + cat <= c) {
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