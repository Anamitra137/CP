#include <iostream>

using namespace std;

class Dsu{
    using T = int;

    T setsize, n;
    T *par, *rank;

    public:
    Dsu(T sz = 0)
    : n{sz}, setsize{sz}, par{new T[sz+1]}, rank{new T[sz+1]}
    {
        for(T i = 1; i <= n; ++i){
            par[i] = i;
            rank[i] = 1;
        }
    }
    ~Dsu(){
        delete[] par;
        delete[] rank;
    }

    T find(T x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(T x, T y){
        T xp = find(x), yp = find(y);
        if(xp != yp){
            if(rank[xp] < rank[yp]) swap(xp, yp);
            par[yp] = xp;
            rank[xp] += rank[yp];
            --setsize;
        }
    }

    T size() { return setsize; }

    void reset(){
        setsize = n;
        for(T i = 1; i <= n; ++i){
            par[i] = i;
            rank[i] = 1;
        }
    }
};


int main() {

    return 0;
}