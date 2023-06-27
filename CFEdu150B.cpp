#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    int q; cin >> q;
    vector<int> a;

    bool flag = false;
    while(q--){
        int x; cin >> x;
        if(a.size() == 0){
            a.push_back(x);
            cout << 1;
            continue;
        }
        
        if(flag){
            if(x >= a.back() && x <= a[0]){
                a.push_back(x);
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
        else{
            if(x >= a.back()){
                a.push_back(x);
                cout << 1;
            }
            else if(x > a[0]){
                cout << 0;
            }
            else{
                a.push_back(x);
                cout << 1;
                flag = true;
            }
        }
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}