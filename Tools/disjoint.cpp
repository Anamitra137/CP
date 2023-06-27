#include <iostream>

using namespace std;

class Dsu {
    private:
    int n, set_size;
    int *par, *rank;

    public:
    Dsu() = default;
    Dsu(std::size_t sz) 
    : n{sz}, set_size{sz}, par{new int[n+1]}, rank{new int[n+1]}
    {
        for(int i = 1; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }

    ~Dsu() {
        delete[] par;
        delete[] rank;
    }

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    int merge(int x, int y) {
        int xp = find(x), yp = find(y);
        if(xp == yp) return xp;
        set_size--;
        if(rank[xp] >= rank[yp]){
            par[yp] = xp;
            rank[xp] += rank[yp];
            return xp;
        }
        else{
            par[xp] = yp;
            rank[yp] += rank[xp];
            return yp;
        }
    }

    int size() { return set_size; }

    void reset(){
        set_size = n;
        for(int i = 1; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }
};


int main() {

    return 0;
}