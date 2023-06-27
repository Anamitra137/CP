#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n; cin >> n;
    long long cnt = 2;
    long long i;
    for(i = 2; i*i < n; i++) {
        if(n % i == 0) {
            cnt += 4;
        }
    }
    if(i*i == n) cnt += 2;
    if(n%2 == 0) cout << cnt-1 << endl;
    else cout << cnt << endl;
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