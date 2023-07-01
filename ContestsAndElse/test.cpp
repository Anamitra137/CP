#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
#define iset indexed_set
#define ll long long int
#define ull unsigned long long int
#define f first
#define int ll
#define s second
#define rep(i, st, end) for (int i = st; i < end; i++)
const int mod = 998244353;
using ii = pair<int, int>;

int dp[1000010];

int n, m;

int rec(int pos)
{
    if (pos == n)
        return 1;

    if (dp[pos] != -1)
        return dp[pos];

    int ans;
    if (pos == n - 1)
    {
        return m - 2;
    }
    else
    {
        ans = ((m - 1) * rec(pos + 1) % mod);
    }

    return dp[pos] = ans;
}

void solve()
{
    cin >> n >> m;
    rep(i, 0, n + 5)
        dp[i] = -1;

    int ans = (m * rec(1)) % mod;
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin>>t; while(t--)
    solve();
}