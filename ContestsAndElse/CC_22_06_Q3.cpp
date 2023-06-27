#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n; cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());
    long long c[n], eq[n];
    for(long long i = 0; i < n; i++) {
        c[i] = upper_bound(a.begin(), a.end(), i) - a.begin();
        eq[i] = upper_bound(a.begin(), a.end(), i) - lower_bound(a.begin(), a.end(), i);
    }

    for(long long i = 0; i < n; i++) {
        long long mn = n-c[i];
        long long mx = n*n - sum + n-c[i] - (n - i) * eq[i];
        cout << mn << ' ' << mx << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}