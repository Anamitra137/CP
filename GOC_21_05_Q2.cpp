#include<bits/stdc++.h>

using namespace std;

void update(vector<string>& grid, int i, int j, int d) {
    for(int k = i; k >= 0; k--) {
        grid[k][j] = 'x';
        for(int l = j-1; l >= max(0, j-; l--) {

        }
    }
}

void solve(){
    long long n, d; 
    cin >> n >> d;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '#') {
                if(d >= 2*n) {
                    string s(n, 'x');
                    for(int k = 0; k < n; k++) cout << s << endl;
                    return;
                }
                update(grid, i, j, d);
            }
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