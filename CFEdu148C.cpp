#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    if(n == 1)
    {
        cout << 1 << '\n';
        return;
    }

    int st = 0, sp = n-1;
    while(st+1 < n && a[st+1] == a[0]) ++st;
    while(sp-1 >= 0 && a[sp-1] == a[n-1]) --sp;

    if(st >= sp)
    {
        cout << 1 << '\n';
        return;
    }

    int ans = 2, inc = a[st+1] - a[st];
    for(int i = st + 1; i <= sp; ++i)
    {
        if(a[i] > a[i-1] && inc < 0)
        {
            ++ans;
            inc = 1;
        }
        else if(a[i] < a[i-1] && inc > 0)
        {
            ++ans;
            inc = -1;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}