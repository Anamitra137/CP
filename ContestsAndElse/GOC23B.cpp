#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<char> st;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(st.size() > 0 && st.back() == s[i]){
            st.pop_back();
            ++cnt;
        }
        else{
            st.push_back(s[i]);
        }
    }

    cout << cnt%k + 1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}