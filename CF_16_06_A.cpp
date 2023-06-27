#include<bits/stdc++.h>

using namespace std;

void solve(){
    int a, b; cin >> a >> b;
    string s{};
    if(a > b) {
        s = '0';
        a--;
        while(b) {
            s = s + "10";
            a--; b--;
        }
        while(a) {
            s = s + '0';
            a--;
        }
    }
    else if(b > a) {
        s = '1';
        b--;
        while(a) {
            s = s + "01";
            a--; b--;
        }
        while(b) {
            s = s + '1';
            b--;
        }
    }
    else {
        while(a) {
            s = s + "01";
            a--;
        }
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