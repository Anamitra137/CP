#include<bits/stdc++.h>

using namespace std;

constexpr int N = 10000000;

int minfac[N+1];

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void sieve2() {
    minfac[0] = minfac[1] = 1;
    for(int i = 2; i <= N; i++) minfac[i] = i;
    for(int i = 2; i*i <= N; i++) {
        if(minfac[i] == i) {
            for(int j = i*i; j <= N; j += i) {
                if(minfac[j] == j) minfac[j] = i;
            }
        }
    }
}

int get_min(int n, int x) {
    int mn = x + n;
    while(n > 1) {
        int f = minfac[n];
        mn = min(mn, (x/f + 1)*f);
        while(f == minfac[n]) n /= f;
    }
    return (mn - x);
}

void solve(){
    int x, y;
    cin >> x >> y;
    if(y-x == 1) {
        cout << -1 << '\n';
        return;
    }
    if(gcd(x,y) != 1) {
        cout << 0 << '\n';
        return;
    }
    cout << get_min(y-x, x)<< '\n'; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t; cin >> t;
    sieve2();
    while(t--){
        solve();
    }

    return 0;
}