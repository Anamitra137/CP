#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<pair<char,char>, int> us;
    for(int i = 0; i < n-1; i++) {
        if(us.find({s[i], s[i+1]}) != us.end() && us[{s[i], s[i+1]}] != i-1) {
            cout << "YES" << '\n';
            return;
        }
        us.insert({{s[i], s[i+1]}, i});
    }
    cout << "NO" << '\n';
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