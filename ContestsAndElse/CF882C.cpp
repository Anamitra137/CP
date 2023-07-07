#include <bits/stdc++.h>

#define FF first
#define SS second
#define MP make_pair

using namespace std;

using ll = long long int;
using ii = pair<int, int>;

constexpr int MOD = 1e9+7;

struct TrieNode
{
    int value;
    TrieNode *arr[2];
};
 
TrieNode *newNode()
{
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}
 
void insert(TrieNode *root, int pre)
{
    TrieNode *temp = root;

    for(int i = 7; i >= 0; --i)
    {
        int val = (pre>>i)&1;
        if(temp->arr[val] == NULL) temp->arr[val] = newNode();
        temp = temp->arr[val];
    } 
    temp->value = pre;
}

int query(TrieNode *root, int pre)
{
    TrieNode *temp = root;
    for(int i = 7; i >= 0; --i)
    {
        int val = (pre>>i)&1;
 
        if(temp->arr[1-val] != NULL) temp = temp->arr[1-val];
        else if(temp->arr[val] != NULL) temp = temp->arr[val];
    }
    return pre^(temp->value);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    TrieNode *root = newNode();
    insert(root, 0);
 
    int ans = INT_MIN, pre = 0;

    for (int i = 0; i < n; ++i)
    {
        pre = pre^a[i];
        insert(root, pre);
        ans = max(ans, query(root, pre));
    }
    
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--)
        solve();

    return 0;
}