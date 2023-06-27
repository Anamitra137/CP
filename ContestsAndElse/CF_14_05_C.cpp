#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> row(n, 0), col(n, 0);
    set<int> X, Y;

    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int x, y; cin >> x >> y;
            if(row[x-1] == 0) X.insert(x-1);
            if(col[x-1] == 0) Y.insert(y-1);
            row[x-1]++;
            col[y-1]++;
        }
        else if(t == 2) {
            int x, y; cin >> x >> y;
            row[x-1]--;
            col[y-1]--;
            if(row[x-1] == 0) X.erase(x-1);
            if(col[x-1] == 0) Y.erase(y-1);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            auto it1 = X.find(x1);
            auto it2 = Y.find(x2);
            // int flag = 1;
            // for (int i = x1-1; i <= x2-1; i++) {
            //     if(row[i] == 0) {flag = 0; break;}
            // }
            // if(flag == 1) {cout << "Yes" << endl; continue;}
            // flag = 1;
            // for (int i = y1-1; i <= y2-1; i++) {
            //     if(col[i] == 0) {flag = 0; break;}
            // }
            // if(flag == 1) cout << "Yes" << endl;
            // else cout << "No" << endl;
        }
    }

    return 0;
}

