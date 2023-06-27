#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t; cin >> t;
    for(int k = 1; k <= t; k++){
        long long n, l; cin >> n >> l;
        vector<pair<long long, long long>> pos; // <position, ith ant>
        vector<long long> L, R;
        deque<long long> Q;
        for(int i = 1; i <= n; i++) {
            long long p, d; cin >> p >> d;
            pos.push_back({p, i});
            if(d == 0) {L.push_back(p);}
            else {R.push_back(l-p);}
        }
        sort(pos.begin(), pos.end());
        sort(L.begin(), L.end());
        sort(R.begin(), R.end());
        for(int i = 0; i < n; i++) {Q.push_back(pos[i].second);}
        cout << "Case #" << k << ": ";
        int i1 = 0, i2 = 0;
        while(i1 < L.size() && i2 < R.size()) {
            if(L[i1] < R[i2]) {cout << Q.front() << " "; Q.pop_front(); i1++;}
            else if(L[i1] > R[i2]) {cout << Q.back() << " "; Q.pop_back(); i2++;}
            else {
                if(Q.front() < Q.back()) {
                    cout << Q.front() << " "; Q.pop_front(); i1++;
                    cout << Q.back() << " "; Q.pop_back(); i2++;
                }
                else {
                    cout << Q.back() << " "; Q.pop_back(); i2++;
                    cout << Q.front() << " "; Q.pop_front(); i1++;
                }
            }
        }
        while(i1 < L.size()) {cout << Q.front() << " "; Q.pop_front(); i1++;}
        while(i2 < R.size()) {cout << Q.back() << " "; Q.pop_back(); i2++;}
        cout << endl;
    }

    return 0;
}