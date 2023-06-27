#include<bits/stdc++.h>

using namespace std;

const int len = 1000001;

void solve(){
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> P(len, 0);
    while(N--) {
        int l, r;
        cin >> l >> r;
        P[l-1] += 1; P[r] += -1;
    }
    for(int i = 1; i < len; i++) P[i] += P[i-1];
    vector<int> cnt(len, 0);
    if(P[0] >= K) cnt[0] = 1;
    else cnt[0] = 0;
    for(int i = 1; i < len; i++) {
        if(P[i] >= K) cnt[i] = cnt[i-1]+1;
        else cnt[i] = cnt[i-1]; 
    }
    while(Q--) {
        int L, R;
        cin >> L >> R;
        if(L==1) cout << cnt[R-1] << '\n';
        else cout << (cnt[R-1] - cnt[L-2]) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long int t; cin >> t;
    // while(t--){
    solve();
    // }

    return 0;
}