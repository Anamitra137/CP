#include<bits/stdc++.h>

using namespace std;

void solve(){
    int w, x, y, z;
    cin >> w >> x >> y >> z;

    if(x > w + y*z) cout << "unfilled" << endl;
    else if(x == w + y*z) cout << "filled" << endl;
    else cout << "overflow" << endl;
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