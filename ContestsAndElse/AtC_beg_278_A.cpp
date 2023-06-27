#include<bits/stdc++.h>

using namespace std;

void solve(){
    int N, K;
    cin >> N >> K;
    int A[N];
    for(auto &i: A) cin >> i;
    for(int i = K; i < N; i++) {
        cout << A[i] << ' ';
    }
    for(int i = 0; i < min(N,K); i++) {
        cout << 0 << ' ';
    }
    cout << endl;
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