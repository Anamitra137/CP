#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
const ll modval = 1000000007;

void solve(){
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(auto &i: A) cin >> i;
    vector<ll> P1(N, 0), P2(N, 0);
    P1[0] = A[0];
    P2[0] = A[0];
    for(int i = 1; i < N; i++) {
        P1[i] = (A[i] + P1[i-1])%modval;
        P2[i] = ( ( (i+1)*A[i] )%modval + P2[i-1] )%modval;
    }
    while(Q--) {
        int L, R;
        cin >> L >> R;
        int ans;
        if(L == 1) {
            ans = P2[R-1]; 
        }
        else {
            ans = ( ((1-L) * (P1[R-1] - P1[L-2]))%modval + P2[R-1]-P2[L-2] )%modval;
        }
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