#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];

    int idxn = -1, idxn_1;
    for(int i = 0; i < n; ++i)
    {
        if(p[i] == n)
        {
            idxn = i;
        }
        if(p[i] == n-1)
        {
            idxn_1 = i;
        }
    }

    int l, r;
    if(idxn == n-1)
    {
        l = r = n-1;
    }
    else if(idxn == 0)
    {
        if(idxn_1 == n-1) 
        {
            l = r = n-1;
        }
        else{

        l = r = idxn_1 - 1;
        }
    }
    else
    {
        l = r = idxn - 1;
    }


    vector<int> ans(n);
    for(int i = 0; i + r + 1 < n; ++i)
    {
        ans[i] = p[i+r+1];
    }
    ans[n-r-1] = p[l];

    int i = l-1, j = n-r;
    while(i > 0 && p[i] > p[0])
    {
        ans[j++] = p[i--];
    }
    int k = 0;
    while(k <= i)
    {
        ans[j++] = p[k++];
    }

    for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
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