#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    char ch = s[0];
    long long ans = 0;
    for(int i = 1; i < n; i++) {
        if(ch != s[i]) {
            ans += i;
            ch = s[i];
        }
    }
    cout << (ans + n) << endl;

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