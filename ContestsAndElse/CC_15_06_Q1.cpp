#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, x; cin >> n >> x;
    if(n < 2*x - 1) {cout << -1 << endl; return;}
    string s;
    if(n%2 == 0) {
        s = "aa"; 
        n -= 2;
    }
    else {
        s = "a";
        n--;
    }
    x--;
    char ch = 'b';
    while(x) {
        s = ch + s + ch;
        x--;
        n -= 2;
        ch += 1;
    }
    while(n) {
        s = 'a' + s + 'a';
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