#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

bool solve(int n){
    int n2 = 2*n, n3 = 3*n;
    cout << n << n2 << n3 << '\n';
    int cnt[10]{0};
    while(n){
        cnt[n%10]++;
        n /= 10;
    }
    while(n2){
        cnt[n2%10]++;
        n2 /= 10;
    }
    while(n3){
        cnt[n3%10]++;
        n3 /= 10;
    }

    for(int i = 1; i <= 9; ++i){
        if(cnt[i] == 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
    cout << solve(783) << '\n';

    return 0;
}