#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void solve(){
    int k; cin >> k;
    string s; cin >> s;
    int n = s.size();

    int head = -1, tail = 0;
    int cnt = 0, last1 = 0;
    ll ans = 0;
    while(tail < n)
    {
        while(head+1 < n)
        {
            if(s[head+1] == '1' && cnt < k)
            {
                last1 = head+1;
                ++cnt;
            }
            else if(s[head+1] == '1' && cnt == k)
            {
                break;
            }
            ++head;
        }


        if(cnt == k) ans += head - last1 + 1;
        // cout << tail << " " << last1 << " " << head << " " << ans << endl;

        if(s[tail] == '1' && cnt > 0) --cnt;
        ++tail;
        if(head < tail) head = tail - 1;
        if(last1 < tail) last1 = tail;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // ll t; cin >> t;
    // while(t--)
        solve();

    return 0;
}