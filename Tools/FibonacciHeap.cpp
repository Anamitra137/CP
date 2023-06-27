#include <iostream>

using namespace std;

struct Fib_node {
    int val, degree;
    Fib_node *left, *right, *parent, *child;
    bool isMarked;

    Fib_node(int x = 0)
    : val{x}, degree{0}, left{this}, right{this},
    parent{nullptr}, child{nullptr}, isMarked{false}
    {}

    void push_left(Fib_node *N) {
        this->left->right = N;
        N->left = this->left;
        this->left = N;
        N->right = this;
        N->parent = this->parent;
    }

    void pop() {
        if(this->left == this) return;
        this->right->left = this->left;
        this->left->right = this->right;
        this->left = this;
        this->right = this;
    }
};

class Fib_Heap {
    private:
    int n;
    Fib_node *minptr;
    Fib_node *A;

    public:
    Fib_Heap() : n{0}, minptr{nullptr}, A{new Fib_node[n]}
    {}

    ~Fib_Heap() {
        // Can be a pain
    }

    void insert(int x) {
        if(minptr) {
            Fib_node *newnode = new Fib_node(x);
            // minptr->left->right = newnode;
            // newnode->left = minptr->left;
            // minptr->left = newnode;
            // newnode->right = minptr;
            minptr->push_left(newnode);
        }
        else {
            minptr = new Fib_node(x);
        }
        if(minptr->val > x) minptr = minptr->left;
    }

    void join(Fib_Heap H) {
        // Definitely will be a pain
    }

    int getMin() const {
        return minptr->val;
    }

    int popMin() {
        if(minptr->child) {
            Fib_node *temp = minptr->child;
            while(temp->right != temp) {
                minptr->child = temp->right;
                temp->pop();
                minptr->push_left(temp);
                temp = minptr->child;
            }
            minptr->push_left(temp);
            minptr->child = nullptr;
        }
        int x = minptr->val;
        minptr = minptr->right;
        minptr->left->pop();
        delete minptr->left;
        // Stuff
        return x;
    }

    void decrease() {
        
    }

};