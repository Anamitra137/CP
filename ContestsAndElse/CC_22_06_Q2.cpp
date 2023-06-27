#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int pre[n], suf[n];
    if(s[0] == '(') pre[0] = 1;
    else pre[0] = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == '(') pre[i] = pre[i-1] + 1;
        else pre[i] = pre[i-1];
    }
    if(s[n-1] == ')') suf[n-1] = 1;
    else suf[n-1] = 0;
    for(int i = n-2; i >= 0 ; i--) {
        if(s[i] == ')') suf[i] = suf[i+1] + 1;
        else suf[i] = suf[i+1];
    }

    int mx = 0;
    for(int i = 0; i < n-1; i++) {
        mx = max(mx, 2*min(pre[i], suf[i+1]));
    }
    cout << n-mx << endl;
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