#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	int T;
	cin >> T;
	while(T--) {
	    ll N, R;
	    cin >> N >> R;
	    vector<ll> A(N), B(N);
	    for(int i = 0; i < N; i++) cin >> A[i];
	    for(int i = 0; i < N; i++) cin >> B[i];
	    
	    vector<pair<ll,ll>> D(N);
	    for(int i = 0; i < N; i++) {
	        D[i] = make_pair(A[i]-B[i], i);
	    }
	    
	    sort(D.begin(), D.end());

        // for(int i = 0; i < N; i++) {
        //     cout << D[i].first << " " << D[i].second << endl;
        // }
	    
	    ll count = 0, cash = R;
        for(int i = 0; i < N && cash >= D[i].first; i++) {
            if(cash >= A[D[i].second]) {
                ll n = (cash - A[D[i].second]) / D[i].first + 1;
                cout << n << endl;
                count += n;
                cash -= n*D[i].first;
            }
        }

        cout << count << endl;
	}
	return 0;
}
