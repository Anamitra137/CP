#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> h(n), a(n);
    for(int i = 0; i < n; ++i) cin >> h[i];
    for(int i = 0; i < n; ++i) cin >> a[i];

    map<int, ll> mp;
    mp[0] = 0;
    for(int i = 0; i < n; ++i){
        auto it = mp.lower_bound(h[i]);
        it--;
        mp[h[i]] = (*it).second + a[i];
        it = mp.find(h[i]);
        it++;
        while(it != mp.end() && mp[h[i]] >= (*it).second){
            it = mp.erase(it);
        }
    }
    
    auto i = mp.end();
    i--;
    cout << (*i).second << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}