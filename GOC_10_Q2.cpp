#include<bits/stdc++.h>

using namespace std;

constexpr long long modval = 1000000007;

long long myPow(int a, int n) {
    long long ans = 1;
    long long base = a;
    while(n) {
        if(n & 1) {
            ans = (ans * base) % modval;
            n--;
        }
        else {
            base = (base * base) % modval;
            n /= 2;
        }
    }
    return ans;
}

void solve(){
    
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