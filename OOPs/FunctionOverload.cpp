#include <iostream>
using namespace std;

int f(int a){
    cout << a << __PRETTY_FUNCTION__ << '\n';
    return 0;
}

void f(int a, double d){
    cout << a*d << __PRETTY_FUNCTION__ << '\n';
}

void f(double a, double d){
    cout << a*d << '\n';
}

void g(int a, int b){
    cout << __PRETTY_FUNCTION__ << '\n';
}
void g(long long int a, long long int b){
    cout << __PRETTY_FUNCTION__ << '\n';
}

int h(int a){
    cout << __PRETTY_FUNCTION__ << '\n';
    return (a);
}
int h(const int a){
    cout << __PRETTY_FUNCTION__ << '\n';
    return (a);
}



int main()
{
    h(1);

    return 0;
}