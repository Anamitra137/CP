#include <bits/stdc++.h>

using namespace std;

void mult(vector<vector<int>>& a, vector<vector<int>>& b){
    int n = a.size();
    vector<vector<int>> mul(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            mul[i][j] = 0;
            for (int k = 0; k < n; ++k) mul[i][j] += a[i][k]*b[k][j];
        }
    }
 
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) a[i][j] = mul[i][j];
    }
}

int power(vector<vector<int>>& F, int n)
{
    vector<vector<int>> M = F;
 
    if (n==1) return F[0][0] + F[0][1];
 
    power(F, n/2);
 
    mult(F, F);
 
    if (n&1) mult(F, M);
 
    return F[0][0] + F[0][1] ;
}

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}