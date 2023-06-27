#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7

void solve(){
    string s; cin >> s;
    string m = "codeforces";
    int cnt = 0;
    for(int i = 0; i < 10; ++i)
    {
        if(s[i] != m[i]) ++cnt;
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}