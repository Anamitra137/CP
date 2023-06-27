#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int cnt = 0, msb = 0;
    while(n) {
        msb = n;
        n /= 10; 
        cnt++;
    }
    cout << ((cnt-1)*9 + msb) << '\n';
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