#include<bits/stdc++.h>

using namespace std;

struct details {
    int sc = 0, mx = 0, ind = -1;
};


void solve(){
    int n; cin >> n;
    unordered_map<string, int> score;
    unordered_map<string, vector<pair<int, int>>> test;

    for(int i = 0; i < n; i++) {
        string s;
        int sc;
        cin >> s >> sc;
        score[s] += sc;
        test[s].push_back({score[s], i});
    }
    int m = 0;
    for(auto i : score) {
        m = max(m, i.second);
    }
    string name;
    int mn = n;
    for(auto i : score) {
        if(m == i.second) {
            for(auto j : test[i.first]) {
                if(j.first >= m && mn > j.second) {
                    mn = j.second;
                    name = i.first;
                }
            }
        }
    }
    cout << name << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}