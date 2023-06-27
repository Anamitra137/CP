// No new operator such as **, <>, or &| can be defined for overloading
// Intrinsic properties of the overloaded operator cannot be change
// Preserves arity
// Preserves precedence
// Preserves associativity
// These operators can be overloaded:
// [] + - * / % ^ & | ~ ! = += -= *= /= %= ^= &= |=
// << >> >>= <<= == != < > <= >= && || ++ -- , ->* -> ( ) [ ]



#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ostream& operator<<(ostream &os, vector<int> &v)
{
	for(auto j : v)
		os << j << ", ";
	return os;
}


class test{
    int x, y;
    public:
    test() = default;
    test(int a, int b) : x{a}, y{b}
    {}

    test operator+(test a){
        test r;
        r.x = this->x + a.x;
        r.y = this->y + a.y;
        return r;
    }

    // ostream& operator<<(ostream& os){
    //     os << this->x << ' ' << this->y;
    //     return os;
    // }

    friend ostream& operator<<(ostream& os, test a){
        os << a.x << ' ' << a.y;
        return os;
    }
};




// struct test{
// 	int x, y;
// };

// test operator+(test &a, test &b)
// {
// 	test c;
// 	c.x = a.x + b.x;
// 	c.y = a.y + b.y;
// 	return c;
// }


int main()
{

	// vector<int> v = {1, 2, 5, -4};
	// cout << v << endl;

	// test a = test(1, 2);
	// test b = test(5, 6);

    // test *c = new test(2, 3);
    // test *d = new test[10];

    // delete c;
    // delete[] d;

    unsigned char buf[100];
    int *pInt = (int*)buf;
    *pInt = 3;
    int *qInt = (int*)(buf + sizeof(int));
    *qInt = 5;


	return 0;}
