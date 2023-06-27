#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; ++i) cin >> x[i];

    vector<pair<int,int>> b(n);
    if(x[0] != 0)
    {
        b[0] = make_pair(x[0], x[0]);
    }
    else
    {
        b[0] = make_pair(1, m);
    }
    for(int i = 1; i < n;)
    {
        if(x[i] != 0) 
        {
            b[i] = make_pair(x[i], x[i]);
            ++i;
        }
        else{
            int j = i;
            while(j < n && x[j] == 0)
            {
                b[j] = make_pair( max(1, x[j-1] - 1), min(m, x[j-1] + 1) ); 
                ++j;
            }
            int r = j;
            --j;
            if(j == n-1)
            {
                break;
            }
            while(j >= i)
            {
                b[j].first = max(b[j].first, b[j+1].first);
                b[j].second = min(b[j].second, b[j+1].second);
            }

            i = r;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(b[i].second - b[i].first < 0)
        {
            cout << 0 << '\n';
            return;
        }
        ans *= (b[i].second - b[i].first + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}