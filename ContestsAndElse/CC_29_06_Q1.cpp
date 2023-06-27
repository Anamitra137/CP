#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int b[n];
    for(int i = 0; i < n; i++) cin >> b[i];
    int a[n];
    a[0] = 0; 
    for(int i = 1; i < n; i++) {
        a[i] = b[i-1] ^ a[i-1];
    }
    if(a[n-1] ^ a[0] == b[n-1]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}