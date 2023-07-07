#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n, d, h; cin >> n >> d >> h;
    vector<int> y(n);
    for(int i = 0; i < n; ++i) cin >> y[i];

    double ans = 0.5*d*h;
    for(int i = 1; i < n; ++i){
        if(y[i-1] + h <= y[i]){
            ans += 0.5*d*h;
        }
        else{
            double x = 1.0*(h - y[i] + y[i-1])*d/h;
            ans += 0.5*(d + x)*(y[i] - y[i-1]);
        }
    }

    printf("%.7lf\n", ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}