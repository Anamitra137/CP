#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

constexpr ll MOD = 1e9+7;

void rec(string& s, int st, int sp, char l, char r)
{
    int i = st, j = sp;
    while(i <= sp && s[i] != r)
    {
        if(s[i] == '?') s[i] = l;
        ++i;
    }

    while(j >= st && s[j] != l)
    {
        if(s[j] == '?') s[j] = r;
        --j;
    }

    if(i > j) return;

    rec(s, i, j, r, l);
}

void solve(){
    string s; cin >> s;

    rec(s, 0, s.size()-1, '0', '1');
    cout << s << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--)
        solve();

    return 0;
}