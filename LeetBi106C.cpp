#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

int solve(vector<int>& nums, string s, int d){
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        if(s[i] == 'R') nums[i] += d;
        else nums[i] -= d;
    }

    sort(nums.begin(), nums.end());

    int ans = 0;
    int contri = n-1;
    for(int i = n-1; i >= 0; --i){
        ans = (ans + (nums[i]*contri)%MOD + MOD)%MOD) % MOD;
        contri -= 2;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}