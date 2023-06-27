#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    long long b[n];
    b[0] = a[0];
    for(int i = 1; i < n; i++) {
        b[i] = b[i-1] + a[n];
    }

    int mn = n, len = 0;
    int ind = -1;
    long long val = 0;
    for(int i = 0; i < n; i++) {
        val ^= a[i];
        if(val == 0) len++;
        else {

        }
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