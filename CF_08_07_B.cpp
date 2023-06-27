#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    vector<bool> visited(n+1, false);
    vector<int> ans;
    int i = 1;
    while(i <= n) {
        int j = i;
        while(j <= n && !visited[j]) {
            ans.push_back(j);
            visited[j] = true;
            j *= 2;
        }
        while(i <= n && visited[i]) i++;
    }
    cout << 2 << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
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