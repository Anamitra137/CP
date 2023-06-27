#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string s;
    if(n & 1) {
        s = "1";
        n--;
    }
    else {
        s = "11";
        n -= 2;
    }
    while(n) {
        s = '0' + s + '0';
        n -= 2;
    }
    cout << s << endl;
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