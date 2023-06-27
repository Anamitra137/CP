#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
    }
    int ans = sum - m;
    if(ans < 0) ans = 0;
    cout << ans << endl;
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