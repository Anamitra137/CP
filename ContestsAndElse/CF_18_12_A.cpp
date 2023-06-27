#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s; cin >> s;
    cout << int(s[0] + s[2] - 2*'0') << '\n';
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