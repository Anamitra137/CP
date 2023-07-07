#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int isflake[1000010]{0};

ll power(int k, int n)
{
    if (n==1) return k;
 
    ll m = power(k, n/2);
    m *= m;
    if(n&1) m *= k;

    return m;
}

void pre(){
    for(int k = 2; k <= 1000; ++k){
        for(int x = 2; ; ++x){
            ll val = (power(k, x+1) - 1)/(k-1);
            if(val > 1000000) break;
            isflake[val] = 1;
        }
    }
}

void solve(){
    int n; cin >> n;
    if(isflake[n]) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}