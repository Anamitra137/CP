#include<bits/stdc++.h>

using namespace std;

bool query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    int size = r-l+1;
    int cnt = 0;
    for(int i = 0; i < size; i++) {
        int a; cin >> a;
        if(a == -1) exit(-1);
        if(a >= l && a <= r) cnt++;
    }
    if(cnt & 1) return true;
    return false;
}

void solve(){
    int n; cin >> n;
    int l = 1, r = n;
    while(l < r) {
        int m = (l + r)/2;
        bool flag = query(l, m);
        if(flag) {
            r = m;
        }
        else {
            l = m+1;
        }
    }
    cout << "? " << l << ' ' << l << endl;
    cout.flush();
    int a; cin >> a;
    if(a == -1) exit(-1);
    cout << "! " << a << endl;
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