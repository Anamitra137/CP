#include<bits/stdc++.h>

using namespace std;

void solve(){
    int H, M;
    cin >> H >> M;
    int h = H, m = M;
    if(H/10 == 0) {
        if(H%10 > 5) {
            h = 10;
            m = 0;
        }
    }
    else if(H/10 == 1) {
        if(H%10 > 5) {
            h = 20;
            m = 0;
        }
    }
    else {
        if(M/10 > 3) {
            h = (H + 1)%24;
            m = 0;
        }
    }
    cout << h << ' ' << m << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long int t; cin >> t;
    // while(t--){
    solve();
    // }

    return 0;
}