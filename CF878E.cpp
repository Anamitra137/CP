#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

void solve(){
    string s1; cin >> s1;
    string s2; cin >> s2;
    int t, q; cin >> t >> q;

    int n = s1.size();
    int mis = 0;
    for(int i = 0; i < n; ++i){
        if(s1[i] != s2[i]) ++mis;
    }

    vector<int> p(q, 0);

    for(int k = 0; k < q; ++k){
        mis += p[k];
        
        int type; cin >> type;

        switch(type){
            case 1:{
                int pos; cin >> pos;
                if(s1[pos-1] != s2[pos-1]){
                    --mis;
                    if(k+t < q) p[k+t]++;
                }
            } break;

            case 2:{
                int num1, pos1, num2, pos2;
                cin >> num1 >> pos1 >> num2 >> pos2;

                if(num1 == num2){
                    int oldmis = 0, newmis = 0;
                    if(s1[pos1-1] != s2[pos1-1]) ++oldmis;
                    if(s1[pos2-1] != s2[pos2-1]) ++oldmis;

                    if(s1[pos1-1] != s2[pos2-1]) ++newmis;
                    if(s1[pos2-1] != s2[pos1-1]) ++newmis;

                    mis += (newmis - oldmis);
                    if(num1 == 1){
                        swap(s1[pos1-1], s1[pos2-1]);
                    }
                    else{
                        swap(s2[pos1-1], s2[pos2-1]);
                    }
                }
                else{
                    if(num1 == 2){
                        swap(pos1, pos2);
                    }

                    int oldmis = 0, newmis = 0;
                    if(s1[pos1-1] != s2[pos1-1]) ++oldmis;
                    if(s1[pos2-1] != s2[pos2-1]) ++oldmis;

                    if(s1[pos1-1] != s1[pos2-1]) ++newmis;
                    if(s2[pos2-1] != s2[pos1-1]) ++newmis;

                    mis += (newmis - oldmis);

                    swap(s1[pos1-1], s2[pos2-1]);                  
                }
            } break;

            case 3:{
                if(mis) cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}