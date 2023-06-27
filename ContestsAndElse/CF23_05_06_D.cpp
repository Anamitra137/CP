#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll N = 1000000000+7;	// 10^9+7

void solve(){
    int n, m;
    cin >> n >> m;

    int mul2 = 0, mul3 = 0;
    int val2 = 1, val3 = 1;
    while(n % val3 == 0)
    {
        mul2 = 0, val2 = 1;
        while(mul2 <= mul3)
        {
            if(val2 * (n / val3) == m)
            {
                cout << "YES" << endl;
                return;
            } 
            val2 *= 2;
            ++mul2;
        }
        val3 *= 3;
        ++mul3;
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}