#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

int nextGap(int n){
    if(n <= 1) return 0;
    return (n+1)/2;
}

void mergeInPlace(vector<int>& A, int l, int r){
    int gap = r-l+1;
    for(gap = nextGap(gap); gap > 0; gap = nextGap(gap)){
        for(int i = l; i + gap <= r; ++i){
            int j = i + gap;
            if(A[i] > A[j]) swap(A[i], A[j]);
        }
    }
}

void mergesort(vector<int>& A, int l, int r){
    if(l == r) return;

    int mid = (l + r)/2;

    mergesort(A, l, mid);
    mergesort(A, mid+1, r);

    mergeInPlace(A, l, r);
}

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}