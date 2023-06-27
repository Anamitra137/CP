#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

void solve(){
    ll N, Q;
    cin >> N >> Q;
    // vector<vector<bool>> mytable(N, vector<bool>(N, false));
    bool mytable[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) mytable[i][j] = false;
    }
    
    while(Q--) {
        int T, A, B;
        cin >> T >> A >> B;
        // assert(A <= N);
        // assert(B <= N);
        if(T==1) mytable[A-1][B-1] = true;
        else if(T==2) mytable[A-1][B-1] = false;
        else {
            if(mytable[A-1][B-1] && mytable[B-1][A-1]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
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