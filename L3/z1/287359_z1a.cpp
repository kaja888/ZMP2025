#include <iostream>

using namespace std;

int main()
{  
    long double tab[2];
    tab[0]=1;
    tab[1]=1;
    long double x;
    cout<<"podaj ktory wyraz ciagu chcesz uzyskac"<<endl;
    cin >> x;
    long double y=0;

    if(x<=2)
	{
      cout << 1;
    }
    else{
      for(int i=0; i<x-1; i++)
	  {
        y=tab[0]+tab[1]; //zmienna pomocnicza.
        tab[0]=tab[1];
        tab[1]=y; 
      }
      cout << y << endl;
    }
   
    return 0;
}
