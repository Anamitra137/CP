#include<bits/stdc++.h>

using namespace std;

void solve(){
    string n; cin >> n;
    if(n.size() == 2) {cout << n[1] << endl; return;}

    char mn = '9';
    for(int i = 0; i < n.size(); i++) mn = min(mn, n[i]);
    cout << mn << endl;
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