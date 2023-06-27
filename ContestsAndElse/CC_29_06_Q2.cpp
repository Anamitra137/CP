#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    long long b[n];
    for(int i = 0; i < n; i++) cin >> b[i];
    long long sum = 0;
    for(int i = 0; i < n; i++) sum += b[i];
    sum /= (n+1);
    for(int i = 0; i < n; i++) cout << b[i] - sum << ' ';
    cout << endl;
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