#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    long long b[n];
    for(int i = 0; i < n+1; i++) cin >> b[i];
    if(n & 1) {
        long long val = 0;
        for(int i = 0; i < n+1; i++) val ^= b[i];
        bool flag = false;
        for(int i = 0; i < n+1; i++) {
            if(!flag && b[i] == val) {flag = true; continue;}
            cout << (val ^ b[i]) << ' ';
        }
        cout << endl;
    }
    else {
        for(int i = 1; i < n+1; i++) {
            cout << (b[0] ^ b[i]) << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}