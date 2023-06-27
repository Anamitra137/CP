#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    long long p[n];
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p, p+n);
    for(int i = 1; i < n; i++) p[i] += p[i-1];

    while(q--) {
        int x, y; cin >> x >> y;
        long long sum;
        if(n > x) sum = p[n-x+y-1] - p[n-x-1];
        else sum = p[n-x+y-1];
        cout << sum << endl;
    }

    return 0;
}