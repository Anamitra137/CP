#include<bits/stdc++.h>

using namespace std;

bool inarr(long long* a, long long s) {
    return (s == a[0] || s == a[1] || s == a[2] || s == a[3]);
}

void solve(){
    int n; cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int cntpos = 0, cntneg = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) cntpos++;
        if(a[i] < 0) cntneg++;
    }

    if(cntpos + cntneg <= 1) cout << "YES" << endl;
    else if(cntpos == 1 && cntneg == 1) {
        long long s = 0;
        for(int i = 0; i < n; i++) s += a[i];
        if(s == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else if((cntpos == 2 && cntneg == 1) || (cntpos == 1 && cntneg == 2)) {
        if(n == 3) {
            long long s = a[0] + a[1] + a[2]; 
            if(a[0] == s || a[1] == s || a[2] == s) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
    else if(cntpos == 2 && cntneg == 2) {
        if(n == 4) {
            long long s = a[0] + a[1] + a[2] + a[3];
            if(inarr(a, s-a[0]) && inarr(a, s-a[1]) && inarr(a, s-a[2]) && inarr(a, s-a[3])) {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
    else cout << "NO" << endl;
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