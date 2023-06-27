#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long sum = 0;
    for (long long i = 0; i < n; i++) sum += a[i];

    vector<vector<long long>> Q(q);
    for (long long i = 0; i < q; i++)
    {
        long long t; cin >> t;
        Q[i].push_back(t);
        long long k; cin >> k;
        Q[i].push_back(k);
        if(t == 1) {
            long long x; cin >> x;
            Q[i].push_back(x);
        }
    }

    for(long long i = 0; i < q; i++) {
        if(Q[i][0] == 1) {
            long long ind = Q[i][1]-1, x = Q[i][2];
            long long val = -1;
            long long j = i-1;
            while(j >= 0) {
                if(Q[j][0] == 2) {
                    val = Q[j][1];
                    break;
                }
                else {
                    if(Q[j][1] - 1 == ind) {
                        val = Q[j][2];
                        break;
                    }
                }
                j--;
            }
            if(val == -1) val = a[ind];
            sum = sum - val + x;
            cout << sum << endl;
        }
        else {
            sum = n*Q[i][1];
            cout << sum << endl;
        }
    }

    return 0;
}