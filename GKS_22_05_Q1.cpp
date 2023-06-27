#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t; cin >> t;
    for(int k = 1; k <= t; k++){
        int n; cin >> n;
        string s; cin >> s;
        int u = 0, l = 0, d = 0, ch = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') u = 1;
            if(s[i] >= 'a' && s[i] <= 'z') l = 1;
            if(s[i] >= '0' && s[i] <= '9') d = 1;
            if(s[i] == '#' || s[i] == '@' || s[i] == '*' || s[i] == '&') ch = 1;
            if(u*l*d*ch == 1) break;
        }
        if(u == 0) {s = s + 'A';}
        if(l == 0) {s = s + 'a';}
        if(d == 0) {s = s + '0';}
        if(ch == 0) {s = s + '#';}
        while(s.size() < 7) {s = s + 'a';}
        cout << "Case #" << k << ": " << s << endl;
    }

    return 0;
}