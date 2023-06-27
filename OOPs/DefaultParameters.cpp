#include <iostream>
using namespace std;

void g(int i, double f, char c = 'a');
void g(int i, double f = 0.0, char c);
void g(int i = 0, double f, char c);

void h(int i = 0, double f = 0.0, char c = 'a'){
    cout << __PRETTY_FUNCTION__ << '\n';
}


void g(int i, double f, char c){
    cout << i << ' ' << f << ' ' << c << '\n';
}

int main(){
    int i = 5; double f = 1.2; char c = 'b';
    g();
    g(i);
    g(i, f);
    g(i, f, c);
    h();
    h(i);
    h(i, f);
    h(i, f, c);
    return 0;
}