#include<bits/stdc++.h>

using namespace std;

void solve(){
    int a[2][2];
    cin >> a[0][0] >> a[0][1];
    cin >> a[1][0] >> a[1][1];
    int sum = a[0][0]+a[0][1]+a[1][0]+a[1][1];
    if(sum == 0) cout << 0 << endl;
    else if(sum >= 1 && sum <= 3) cout << 1 << endl;
    else cout << 2 << endl;
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