#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    int a[m];
    for(int i = 0; i < m; i++) cin >> a[i];
    vector<int> cnt(n+1, 0);
    for(int i = 0; i < m; i++) {
        cnt[a[i]]++;
    }
    // set<pair<int, int>> hours;
    // for(int i = 1; i <= n; i++) {
    //     hours.insert(make_pair(cnt[i], i));
    // }
    // auto l = hours.begin();
    // auto h = hours.end();
    // h--;
    // while((*h).first - (*l).first >= 3) {
    //     pair<int, int> mx = *h, mn = *l;
    //     mx.first -= 1;
    //     mn.first += 2;
    //     hours.erase(h);
    //     hours.erase(l);
    //     hours.insert(mx);
    //     hours.insert(mn);
    //     l = hours.begin();
    //     h = hours.end();
    //     h--;
    // }
    // cout << (*h).first << endl;

    multiset<int> hours;
    for(int i = 1; i <= n; i++) {
        hours.insert(cnt[i]);
    }
    auto l = hours.begin();
    auto h = hours.end();
    h--;
    while((*h) - (*l) >= 3) {
        int mx = *h, mn = *l;
        mx -= 1;
        mn += 2;
        hours.erase(h);
        hours.erase(l);
        hours.insert(mx);
        hours.insert(mn);
        l = hours.begin();
        h = hours.end();
        h--;
    }
    cout << (*h) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}