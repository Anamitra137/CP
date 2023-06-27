#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

const ll modval = 1000000007;

void solve(){
    int N, Q;
    cin >> N >> Q;
    ll A[N], P[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    P[0] = A[0];
    for(int i = 1; i < N; i++) P[i] = (A[i] + P[i-1])%modval;
    while(Q--) {
        int L, R;
        cin >> L >> R;
        int ans;
        if(L == 1) ans = P[R-1];
        else ans = (P[R-1]-P[L-2])%modval;
        if(ans < 0) ans += modval;
        cout << ans << '\n';
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