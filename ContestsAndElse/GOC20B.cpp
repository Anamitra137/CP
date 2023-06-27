#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int cnt[26];

bool check(int k){
    int total = 0;
    int mx1 = 0, mx2 = 0;

    for(int i = 0; i < 26; ++i){
        total += cnt[i];
        if(cnt[i] >= mx1){
            mx2 = mx1;
            mx1 = cnt[i];
        }
		else if(cnt[i] > mx2){
			mx2 = cnt[i];
		}
    }

    return (total - mx1 - mx2 <= k);
}


void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    for(int i = 0; i < 26; ++i) cnt[i] = 0;

    int head = -1, tail = 0;
    int ans = 0;
    while(tail < n){
        while(head+1 < n){
            ++head;
            ++cnt[s[head]-'a'];
            if(!check(k)){
                --cnt[s[head]-'a'];
                --head;
                break;
            }
        }
        ans = max(ans, head-tail+1);
        --cnt[s[tail]-'a'];
        ++tail;
        if(head < tail) head = tail-1; 
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}