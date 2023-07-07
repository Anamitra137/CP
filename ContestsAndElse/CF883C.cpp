#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

bool comp(ii a, ii b){
    if(a.FF > b.FF) return true;
    else if(a.FF == b.FF) return a.SS < b.SS;
    else return false;
}

void solve(){
    int n, m, h; cin >> n >> m >> h;
    vector<ii> a(n);
    for(int i = 0; i < n; ++i){
        vector<int> t(m);
        for(int j = 0; j < m; ++j) cin >> t[j];
        sort(t.begin(), t.end());
        int sum = 0, last = 0; 
        int j = 0;
        for(j = 0; j < m; ++j){
            if(last + t[j] > h){
                break;
            }
            last += t[j];
            sum += last;
        }
        a[i] = MP(j, sum);
    }
    ii key = a[0];
    sort(a.begin(), a.end(), comp);
    int idx = lower_bound(a.begin(), a.end(), key, comp) - a.begin();
    cout << idx+1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}