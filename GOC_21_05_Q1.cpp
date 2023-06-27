#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n, k; cin >> n >> k;
    vector<long long> a(n), p(n);
    for(int i = 0; i < n; i++) {cin >> a[i]; a[i] -= k;}
    p[0] = a[0];
    for(int i = 1; i < n; i++) p[i] = a[i] + p[i-1];
    unordered_map<long long, long long> m;
    long long count = 0;
    for(int i = 0; i < n; i++) {
        if(p[i] == 0) count++;
        m[p[i]]++;
    }
    for(auto i : m) {
        count += (i.second * (i.second - 1)) / 2;
    }

    cout << count << endl;
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