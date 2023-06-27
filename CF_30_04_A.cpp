#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;

    if(s.size() % 2 == 0) {
        int score = 0;
        for(auto i : s) {
            score += i - 'a' + 1;
        }
        cout << "Alice" << " " << score << endl;
        return;
    }

    if(s.size() == 1) {
        int score = s[0] - 'a' + 1;
        cout << "Bob" << " " << score << endl;
        return;
    }

    int Ascore = 0, Bscore = 0;
    if(s[0] < s[s.size() - 1]) {
        Bscore = s[0] - 'a' + 1;
        for(int i = 1; i < s.size(); i++) {
            Ascore += s[i] - 'a' + 1;
        }
    }
    else {
        Bscore = s[s.size() - 1] - 'a' + 1;
        for(int i = 0; i < s.size() - 1; i++) {
            Ascore += s[i] - 'a' + 1;
        }
    }
    if(Ascore > Bscore) {
        cout << "Alice" << " " << (Ascore - Bscore) << endl;
    }
    else {
        cout << "Bob" << " " << (Bscore - Ascore) << endl;        
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}