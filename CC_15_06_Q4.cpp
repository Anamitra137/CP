#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    if(n % 2 == 1) {
        cout << -1 << endl;
        return;
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