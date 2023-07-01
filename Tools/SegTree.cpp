#include <bits/stdc++.h>

using namespace std;

int a[100010];
int t[400040];

void build(int idx, int l, int r){
    if(l == r) {
        t[idx] = a[l];
        return;
    }

    int mid = (l + r)/2;
    build(idx*2, l, mid);
    build(idx*2 + 1, mid+1, l);

    t[idx] = t[2*idx] + t[2*idx + 1];
}

void update(int idx, int l, int r, int pos, int val){
    if(pos < l || r < pos) return;
    if(l == r){
        t[idx] = val;
        a[l] = val;
        return;
    }

    int mid = (l + r)/2;
    update(idx*2, l, mid, pos, val);
    update(idx*2 + 1, mid+1, r, pos, val);

    t[idx] = t[2*idx] + t[2*idx + 1];
}

int query(int idx, int l, int r, int lq, int rq){
    if(r < lq || rq < l) return 0;
    if(lq <= l && r <= rq) return t[idx];

    int mid = (l + r)/2;
    return query(2*idx, l, mid, lq, rq) + query(2*idx + 1, mid+1, r, lq, rq);
}

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}