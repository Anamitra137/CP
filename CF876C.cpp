#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    if(a[n-1] == 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    vector<int> ans;
    ans.push_back(0);
    int last1 = n-2;
    for(int i = n-2; i >= 0;)
    {
        if(a[i] == 0)
        {
            ans.push_back(0);
            --i;
        }
        else
        {
            last1 = i;
            while(i-1 >= 0 && a[i-1] == 1)
            {
                ans.push_back(0);
                --i;
            }
            ans.push_back(last1-i+1);
            --i;
        }
    }

    for(auto i : ans) cout << i << ' ';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}