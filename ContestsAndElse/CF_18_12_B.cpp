#include<bits/stdc++.h>

using namespace std;

void solve(){
    int m[2][2];
    cin >> m[0][0] >> m[0][1];
    cin >> m[1][0] >> m[1][1];
    if(((m[0][0] < m[0][1] && m[1][0] < m[1][1]) || (m[0][0] > m[0][1] && m[1][0] > m[1][1])) && ((m[0][0] < m[1][0] && m[0][1] < m[1][1]) || (m[0][0] > m[1][0] && m[0][1] > m[1][1]))) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
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