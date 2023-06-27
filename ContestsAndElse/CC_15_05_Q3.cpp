#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long val = a[0];
    for(int i = 1; i < n; i++) val = val & a[i];
    long long temp = a[0], count = 1, op = 0;
    for(int i = 1; i < n; i++) {
        if(temp == val) {
            op = op + count - 1;
            count = 1;
            temp = a[i];
        }
        else {
            temp = temp & a[i];
            count++;
        }
    }
    if(temp == val) op = op + count - 1;
    else op = op + count;
    cout << op << endl;
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