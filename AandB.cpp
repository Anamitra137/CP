#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long a, b; cin >> a >> b;
    long long d = abs(b-a);
    int i = 0;
    while(i*(i+1)/2 < d) i++;
    while((d + i*(i+1)/2) % 2 != 0) i++;
    cout << i << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}