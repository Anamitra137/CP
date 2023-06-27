#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t; cin >> t;
    for(int k = 1; k <= t; k++){
        long long n, x, y;
        cin >> n >> x >> y;
        long long total = n*(n+1)/2;
        if(total % (x+y) != 0) {cout << "Case #" << k << ": IMPOSSIBLE" << endl; continue;}
        long long sum = total*x / (x+y);
        vector<int> A;
        for(int i = n; i >= 1; i--) {
            if(sum >= i) {
                sum -= i;
                A.push_back(i);
            }
        }
        cout << "Case #" << k << ": POSSIBLE" << endl;
        cout << A.size() << endl;
        for(int i = 0; i < A.size(); i++) cout << A[i] << " ";
        cout << endl;
    }

    return 0;
}