#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    map<int, int> mp1, mp2;
    int last1 = -1, last2 = -1;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == last1)
        {
            ++cnt1;
        }
        else
        {
            mp1[last1] = max(mp1[last1], cnt1);
            last1 = a[i];
            cnt1 = 1;
        }

        if(b[i] == last2)
        {
            ++cnt2;
        }
        else
        {
            mp2[last2] = max(mp2[last2], cnt2);
            last2 = b[i];
            cnt2 = 1;
        }
    }

    mp1[last1] = max(mp1[last1], cnt1);
    mp2[last2] = max(mp2[last2], cnt2);

    int ans = 0;
    for(auto it : mp1)
    {
        ans = max(ans, it.second + mp2[it.first]);
    }
    for(auto it : mp2)
    {
        ans = max(ans, it.second + mp1[it.first]);
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