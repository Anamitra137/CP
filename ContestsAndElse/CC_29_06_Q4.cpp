#include<bits/stdc++.h>

using namespace std;

bool isSet(long long a, int i) {
    return a & (1<<i);
}

void solve(){
    int n; cin >> n;
    long long a, b; cin >> a >> b;
    long long x = 0;
    long long ta = 0, tb = 0;
    for(int i = 0; i < n; i++) {
        if(isSet(a, i) && isSet(b, i)) {
            ta += (1<<i);
            tb += (1<<i);
        }
        if(!isSet(a, i) && !isSet(b, i)) {
            x += (1<<i);
            ta == (1<<i);
            tb == (1<<i);
        }
        if(isSet(a, i) && !isSet(b, i)) {
            if(ta > tb) {
                x += (1<<i);
                tb += (1<<i);
            }
            else ta += (1<<i);
        }
        if(!isSet(a, i) && isSet(b, i)) {
            if(ta < tb) {
                x += (1<<i);
                ta += (1<<i);
            }
            else tb += (1<<i);
        }
    }
    cout << x << endl;
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