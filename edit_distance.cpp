#include <iostream>
#include <vector>
#include <string>

using namespace std;

int edit_dist(string X, string Y) {
    constexpr int cost_insert{1};
    constexpr int cost_delete{1};
    constexpr int cost_substitute{1};
    // constexpr int cost_flip{2};

    int n = X.size(), m = Y.size();
    vector<vector<int>> d(n+1, vector<int>(m+1));
    for(int i = 0; i <= n; i++) d[i][0] = i*cost_delete;
    for(int j = 1; j <= m; j++) d[0][j] = j*cost_insert;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int ins = d[i][j-1] + cost_insert;
            int del = d[i-1][j] + cost_delete;
            int sub = d[i-1][j-1] + cost_substitute*((X[i-1] == Y[j-1]) ? 0 : 1);
            d[i][j] = min(ins, min(del, sub));
            // if(i > 1 && j > 1 && X[i-2] == Y[j-1] && X[i-1] == Y[j-2]) {
            //     int flp = d[i-2][j-2] + cost_flip;
            //     d[i][j] = min(d[i][j], flp);
            // }
        }
    }

    return d[n][m];
}

int main() {
    string s1{"sunday"}, s2{"saturday"};
    cout << edit_dist(s1, s2) << endl;

    return 0;
}