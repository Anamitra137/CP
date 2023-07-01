#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<ii> b(n);
    for(int i = 0; i < n; ++i) b[i] = MP(a[i], i);
    sort(b.begin(), b.end());

    int lo = 0, hi = n-1;
    int ans = 0;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        bool flag = false;
        
        int cnt = 0;
        int head = c-1, tail = 0;
        for(int i = tail; i <= head; ++i){
            if(i == b[mid].SS || a[i] > b[mid].FF) {
                ++cnt;
            }
        }
        if(cnt > c/2){
            flag = true;
        }
        
        while(!flag && head+1 < n){
            ++head; ++tail;
            if(a[tail-1] > b[mid].FF || tail-1 == b[mid].SS) --cnt;
            if(a[head] > b[mid].FF || head == b[mid].SS) ++cnt;
            if(cnt > c/2){
                flag = true;
            }
        }

        if(flag){
            ans = 1 + b.end() - upper_bound(b.begin(), b.end(), MP(b[mid].FF, n));
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}