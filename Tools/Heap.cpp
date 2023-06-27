#include <iostream>

using namespace std;

class Max_heap{
    private:
    int size, *H;

    public:
    Max_heap(int n) {
        size = 0;
        H = new int[n+1];
    }

    ~Max_heap() {
        delete[] H;
    }

    int findMax() const{
        return H[1];
    }

    void insert(int x) {
        size++;
        H[size] = x;
        int i = size;
        while(H[i/2] < H[i] && i > 1) {
            swap(H[i/2], H[i]);
            i /= 2;
        }
    }

    int deleteMax() {
        if(size == 0) return -1;

        int it = H[1];

        if(size == 1) {
            size--;
            return it;
        }

        H[1] = H[size];
        size--;
        int i = 1;
        while(true) {
            int l, r;
            l = 2*i;
            r = 2*i + 1;

            if(l > size) return it;
            if(r > size) {
                if(H[i] < H[l]) {
                    swap(H[i], H[l]);
                }
                return it;
            }
            else {
                int max = r;
                if(H[l] > H[r]) max = l;
                if(H[i] < H[max]) swap(H[i], H[max]);
                i = max;
            }
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << H[i] << " ";
        }
        cout << endl;
    }

    int currentSize() {
        return size;
    }
};

int main() {
    // MaxpriorityQ Q;
    // Q.create(10);

    // Q.insert(2);
    // Q.insert(5);
    // Q.insert(100);
    // Q.insert(84);
    // Q.insert(7);
    // Q.insert(12);
    // cout << Q.deleteMax() << endl;
    // cout << Q.deleteMax() << endl;
    // cout << Q.deleteMax() << endl;
    // cout << Q.deleteMax() << endl;
    // cout << Q.deleteMax() << endl;
    // cout << Q.deleteMax() << endl;
    // cout << Q.deleteMax() << endl;
    return 0;
}