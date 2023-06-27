#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    if (n % 2 == 1 || n < 4)
    {
        cout << -1 << endl;
        return;
    }
    if (n % 6 == 0)
        cout << n / 6 << " " << n / 4 << endl;
    else
        cout << (n / 6 + 1) << " " << n / 4 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}