#include<bits/stdc++.h>

using namespace std;

void myDFS(const vector<vector<pair<int,int>>>& G, vector<int>& nodeCount, int ind, int par) {
    nodeCount[ind] = 1;
    for(int i = 0; i < G[ind].size(); i++) {
        int j = G[ind][i].first;
        if(j != par) {
        myDFS(G, nodeCount, j, ind);
        nodeCount[ind] += nodeCount[j];
        }
    }
}

void solve(){
    int n, k; cin >> n >> k;
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<vector<pair<int,int>>> G(n);
    for(int i = 0; i < n-1; i++) {
        int u, v, x; cin >> u >> v >> x;
        G[u-1].push_back({v-1, x});
        G[v-1].push_back({u-1, x});
    }

    vector<int> nodeCount(n);
    myDFS(G, nodeCount, 0, -1);

    int infected = n;
    priority_queue<pair<int, pair<int,int>>> Q; // <nodeCount, <weight from parent index, index>>
    for(int i = 0; i < G[0].size(); i++) {
        int j = G[0][i].first;
        int x = G[0][i].second;
        Q.push({nodeCount[j], {x, j}});
    }
    int count = 0;
    vector<int> visited(n, 0);
    visited[0] = 1;
    while(!Q.empty()) {
        int xcurr = Q.top().second.first;
        int ind = Q.top().second.second;
        int num = Q.top().first;
        Q.pop();
        if(xcurr && infected > k) {     
            count++;
            infected -= num;
        }
        else {
            for(int i = 0; i < G[ind].size(); i++) {
                int j = G[ind][i].first;
                int x = G[ind][i].second;
                if(!visited[j]) {Q.push({nodeCount[j], {x, j}}); visited[j] = 1;}
            }
        }
        if(infected <= k) {cout << count << endl; return;}
    }

    cout << -1 << endl;
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