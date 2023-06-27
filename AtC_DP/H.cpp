#include <bits/stdc++.h>

using namespace std;

constexpr long long modval = 1000000007;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) cin >> a[i][j];
    }

    vector<vector<long long>> p(h, vector<long long>(w, 0));
    for(int j = 1; j < w; j++) {
        if(a[0][j] == '#') break;
        p[0][j] = 1;
    }
    for(int i = 1; i < h; i++) {
        if(a[i][0] == '#') break;
        p[i][0] = 1;
    }
    for(int i = 1; i < h; i++) {
        for(int j = 1; j < w; j++) {
            if(a[i][j] == '#') continue;
            p[i][j] = (p[i-1][j] + p[i][j-1]) % modval;
        }
    }
    cout << p[h-1][w-1] << endl;

    return 0;
}