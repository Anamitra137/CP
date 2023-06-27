#include<bits/stdc++.h>

using namespace std;

void solve(){
    int m; cin >> m;
    vector<string> wall(2);
    cin >> wall[0] >> wall[1];
    bool ans1 = true, ans2 = true;
    if(wall[0][0] == 'B') {
        int i = 0, j = 0;
        bool flag = true;
        while(j < m-1) {
            if(wall[(i+1)%2][j] == 'B' && flag) {
                i = (i+1)%2;
                flag = false;
            }
            else if(wall[i][j+1] == 'B') {
                j = j+1;
                flag = true;
            }
            else {
                ans1 = false;
                break;
            }
        }
        if(ans1 && wall[i][m-1] != 'B') ans1 = false;
    }
    if(wall[1][0] == 'B') {
        int i = 1, j = 0;
        bool flag = true;
        while(j < m-1) {
            if(wall[(i+1)%2][j] == 'B' && flag) {
                i = (i+1)%2;
                flag = false;
            }
            else if(wall[i][j+1] == 'B') {
                j = j+1;
                flag = true;
            }
            else {
                ans2 = false;
                break;
            }
        }
        if(ans1 && wall[i][m-1] != 'B') ans2 = false;
    }
    if(wall[0][0] == 'B' && wall[1][0] == 'B') {
        if(ans1 | ans2) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else if(wall[0][0] == 'B' && ans1) cout << "YES" << '\n';
    else if(wall[1][0] == 'B' && ans2) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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