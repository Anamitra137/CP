#include<bits/stdc++.h>

using namespace std;

void solve(){
    int k, n;
    cin >> k >> n;
    int m = floor(( 1 + sqrt(1 + 8*(n-k)) )/2);
    m = min(m, k-1);
    int curr = 1;
    cout << 1 << ' ';
    for(int i = 0; i < k-m-1; i++) {
        curr += 1;
        cout << curr << ' ';
    }
    for(int i = 1; i <= m; i++) {
        curr += i;
        cout << curr << ' ';
    }
    cout << '\n';
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