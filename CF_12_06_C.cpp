#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;

    if(n == 1) {
        if(s[0] == t[0]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    // for(int i = 0; i < n-1; ) {
    //     if(s[i] != t[i]) {
    //         if(s[i] == 'a' && t[i] == 'b') {
    //             int j = i+1;
    //             while(s[i] == 'a' && t[i] == 'a') j++;
    //             if(s[j] == 'b' && t[j] == 'a') swap(s[i], s[j]);
    //             i = j;
    //         }
    //         else if(s[i] == 'b' && t[i] == 'c' && s[i+1] == 'c') {
    //             swap(s[i], s[i+1]);
    //         }
    //         else {
    //             cout << "NO" << endl;
    //             return;
    //         }
    //     }
    // }
    // if(s[n-1] != t[n-1]) cout << "NO" << endl;
    // else cout << "YES" << endl;
    vector<int> pa, pb, pc;
    for(int i = 0; i < n; i++) {
        if(t[i] == 'a') pa.push_back(i);
        else if(t[i] == 'b') pb.push_back(i);
        else pc.push_back(i);
    }
    int ar = 0, bl = 0, br = 0, cl = 0;
    int ia = 0, ib = 0, ic = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') ar += pa[ia++] - i;
        else if(s[i] == 'b') {
            if(pb[ib] - i > 0) br += pb[ib] - i;
            else bl += i - pb[ib];
            ib++;
        }
        else cl += i - pc[ic++];
        if(ia >= pa.size() || ib >= pb.size() || ic >= pc.size())
    }
    if(ar == bl && br == cl) cout << "YES" << endl;
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