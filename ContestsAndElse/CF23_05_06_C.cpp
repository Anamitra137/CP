#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7

void solve(){
    int n; cin >> n;
    vector<int> m(n);
    vector<string> s(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> m[i] >> s[i];
    }
    
    int mn01 = INT_MAX, mn10 = INT_MAX, mn11 = INT_MAX;

    for(int i = 0; i < n; ++i)
    {
        if(s[i] == "01") mn01 = min(mn01, m[i]);
        else if(s[i] == "10") mn10 = min(mn10, m[i]);
        else if(s[i] == "11") mn11 = min(mn11, m[i]);
    }
    if((mn01 == INT_MAX || mn10 == INT_MAX) && mn11 == INT_MAX) cout << -1 << endl;
    else if(mn01 == INT_MAX || mn10 == INT_MAX) cout << mn11 << endl;
    else if(mn11 == INT_MAX) cout << mn01+mn10 << endl;
    else cout << min(mn01+mn10, mn11) << endl;
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