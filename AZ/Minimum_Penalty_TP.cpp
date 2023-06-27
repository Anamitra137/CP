#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

int freq[1000001] = {0};
int cntdist = 0;

void add(int x)
{
    ++freq[x];
    if(freq[x] == 1) ++cntdist;
}

void remove(int x)
{
    --freq[x];
    if(freq[x] == 0) --cntdist;
}

void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(auto &i: a) cin >> i;

    memset(freq, 0, sizeof(freq));
    cntdist = 0;

    int head = d-1, tail = 0;
    for(int i = 0; i < d; ++i)
    {
        add(a[i]);
    }
    int ans = cntdist;

    while(head+1 < n)
    {
        ++head;
        add(a[head]);
        remove(a[tail]);
        ++tail;
        ans = min(ans, cntdist);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}