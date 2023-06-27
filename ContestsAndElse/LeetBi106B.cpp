#include <bits/stdc++.h>

#define FF first
#define SS second

using namespace std;

using ll = long long int;

constexpr int MOD = 1e9+7;

int solve(string s){
    int n = s.size();
    int head = -1, tail = 0;
    int cnt = 0;
    int ans = 0;
    while(tail < n){
        while(head+1 < n){
            ++head;
            if(head+1 < n && s[head] == s[head+1]) ++cnt;
            if(cnt == 2) break;
        }
        ans = max(ans, head-tail+1);
        while(tail < n){
            ++tail;
            if(tail < n && s[tail-1] == s[tail]) --cnt;
            if(cnt < 2) break;
        }
        if(head < tail) head = tail-1;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
    string s; cin >> s;
    cout << solve(s) << '\n';

    return 0;
}