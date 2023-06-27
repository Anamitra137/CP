#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n == 1) {cout << "YES" << endl; cout << s << endl; return;}
    if(n == 2) {
        if(s[0] == s[1]) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << s << endl;
        }
    }
    vector<int> c(26, 0);
    for(int i = 0; i < n; i++) c[s[i]-'a']++;
    vector<pair<int, char>> v;
    for(char i = 'a'; i <= 'z'; i++) {
        if(c[i-'a'] > 0) v.push_back(make_pair(c[i-'a'], i));
    }
    sort(v.begin(), v.end(), greater<pair<int, char>>());

    string ans = "";
    while(v[0].first) {
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first == 0) break;
            ans = ans + v[i].second;
            v[i].first--;
        }
    }
    if(ans[n-1] == ans[n-3] || ans[n-1] == ans[n-2]) {cout << "NO" << endl; return;}
    cout << "YES" << endl;
    cout << ans << endl;
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