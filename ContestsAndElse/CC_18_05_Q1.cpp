#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int val = 0, count = 0;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        if(k != val) {count++; val = k;}
    }
    cout << count << endl;
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