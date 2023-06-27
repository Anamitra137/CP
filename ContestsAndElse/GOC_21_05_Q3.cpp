#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<string> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    vector<vector<int>> count(n, vector<int>(26, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < A[i].size(); j++) {
            count[i][A[i][j] - 'a']++;
        }
    }
    for(int j = 0; j < 26; j++) {
        for(int i = 1; i < n; i++) {
            count[i][j] += count[i-1][j];
        }
    }
    while(m--){
        int l, r;
        long long k;
        cin >> l >> r >> k;
        
        long long sum = 0;
        for(int j = 0; j < 26; j++) {
            sum += count[r-1][j];
            if(l-2 >= 0) sum -= count[l-2][j];
            if(sum >= k) {cout << char('a' + j) << endl; break;}
        }
    }

    return 0;
}