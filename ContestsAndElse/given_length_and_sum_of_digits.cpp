#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s; cin >> m >> s;
    if(m == 1 && s == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    if(s > m*9 || s == 0) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    vector<int> A(m, 0), B;
    int i = 0;
    while(s > 0) {
        A[i] = ((s > 9) ? 9 : s);
        s -= 9;
        i++;
    }
    B = A;
    if(B[m-1] == 0) {
        B[m-1] = 1;
        for(int i = m-2; i >= 0; i--) {
            if(B[i] != 0) {B[i]--; break;}
        }
    }

    for(int i = m-1; i >= 0; i--) cout << B[i];
    cout << " ";
    for(int i = 0; i < m; i++) cout << A[i];
    cout << endl;

    return 0;
}