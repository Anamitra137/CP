#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long a, b, n;
    cin >> a >> b >> n;
    
    if(a == b) {
        cout << 0 << endl;
        return;
    }
    if(n == 1) {
        cout << -1 << endl;
        return;
    }
    if(n > (b^a)) {
        cout << 1 << endl;
    }
    else {
        int len = 0;
        long long n1 = (a^b);
        while(n1) {n1 = n1>>1; len++;}
        if(n > (1<<(len-1))) {
            cout << 2 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
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