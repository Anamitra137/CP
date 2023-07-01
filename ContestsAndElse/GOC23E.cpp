#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int n;
int a[10010];
int t[40040];
bitset<1001> tmp[40040];

void build(int idx, int l, int r){
    if(l == r){
        tmp[idx].reset();
        tmp[idx].set(a[l]);
        t[idx] = 1;
        return;
    }

    int mid = (l + r)/2;
    build(idx*2, l, mid);
    build(idx*2 + 1, mid+1, r);

    tmp[idx] = tmp[idx*2] ^ tmp[idx*2 + 1];

    t[idx] = tmp[idx].count();
}

void update(int idx, int l, int r, int pos, int v){
    if(pos < l || r < pos) return;
    if(l == r){
        a[l] = v;
        tmp[idx].reset();
        tmp[idx].set(a[l]);
        t[idx] = 1;
        return;
    }

    int mid = (l + r)/2;
    update(idx*2, l, mid, pos, v);
    update(idx*2 + 1, mid+1, r, pos, v);

    tmp[idx] = tmp[idx*2] ^ tmp[idx*2 + 1];

    t[idx] = tmp[idx].count();
}

bitset<1001> query(int idx, int l, int r, int lq, int rq){
    if(r < lq || rq < l) return bitset<1001>(0);
    if(lq <= l && r <= rq) return tmp[idx];

    int mid = (l + r)/2;
    return query(2*idx, l, mid, lq, rq) ^ query(2*idx + 1, mid+1, r, lq, rq);
}

void solve(){
    int q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    // for(int i = 0; i < 40040; ++i){
    //     for(int j = 0; j < 1001; ++j) tmp[i][j] = 0;
    // }
    build(1, 1, n);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int i, v; cin >> i >> v;
            update(1, 1, n, i, v);
        }
        else{
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r).count() << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int _t; cin >> _t;
    // while(_t--)
        solve();

    return 0;
}