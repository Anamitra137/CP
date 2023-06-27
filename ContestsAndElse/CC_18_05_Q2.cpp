#include<bits/stdc++.h>

using namespace std;

const long long modval = 1e9 + 7;

int choice(char ch) {
    if(ch == 'c' || ch == 'g' || ch == 'l' || ch == 'r') return 2;
    else return 1;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    long long ans = 1;
    for(int i = 0; i < n; i++) {
        ans = (ans * choice(s[i])) % modval;
    }
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