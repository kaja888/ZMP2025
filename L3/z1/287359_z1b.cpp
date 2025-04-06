#include <iostream>

using namespace std;

int Fib(long double n, long double a=1, long double b=0) {
    if (n == 0) {
        return a+b;
    }
    return Fib(n-1,b,a+b);

}

int main(){
    long double x, y;
    cout<<"podaj ktory wyraz ciagu chcesz uzyskac"<<endl;
    cin >> x;
	cout<<Fib(x);

    return 0;
}
