#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    cout << ((1LL<<(2*n)) - 3*(1LL<<n) + 2) << endl;
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