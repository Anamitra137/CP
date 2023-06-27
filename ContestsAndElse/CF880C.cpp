#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int mn[] = {0, 1, 10, 100, 1000, 10000, 100000};
int mx[] = {0, 9, 99, 999, 9999, 99999, 999999};

void solve(){
    int A, B, C; cin >> A >> B >> C;
    ll k; cin >> k;

    if(max(A, B) == C){
        ll cnt = 0;
        for(int a = mn[A]; a <= min(mx[A], mx[C] - mn[B]); ++a){
            int total = min(mx[C]-a, mx[B]) - mn[B] + 1;
            // cout << a << ' ' << cnt << ' ' << total << '\n';
            if(cnt + total >= k){
                int b = mn[B] + (k-cnt) - 1;
                cout << a << " + " << b << " = " << (a+b) << '\n';
                return;
            }
            else{
                cnt += total;
            }
        }

    }
    else if(max(A, B) + 1 == C){
        ll cnt = 0;
        for(int a = max(mn[A], mn[C]-mx[B]); a <= mx[A]; ++a){
            int bmin = max(mn[B], mn[C]-a);
            int total = mx[B] - bmin + 1;
            // cout << a << ' ' << cnt << ' ' << total << '\n';
            if(cnt + total >= k){
                int b = bmin + (k-cnt) - 1;
                cout << a << " + " << b << " = " << (a+b) << '\n';
                return;
            }
            else{
                cnt += total;
            }
        }
    }
    
    cout << -1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}