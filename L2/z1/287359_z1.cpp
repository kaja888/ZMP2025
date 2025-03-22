#include<iostream>

using namespace std;

int NWD(int a, int b)
{
    while(a!=b)
       if(a>b)
           a-=b;
       else
           b-=a; 
    return a; 
}

int main()
{
	int n;
	int nwd=0;
	cout<<"wpisz z ilu liczb chcesz uzyskać NWD"<<endl;
	cin>>n;
	cout<<"podaj liczby których NWD chcesz policzyć"<<endl;
	int tab[n];
	for(int i=0;i<n;i++)
	{
		cin>>tab[i];
	}
	nwd=NWD(tab[0],tab[1]);
	for(int i=2;i<n;i++)
	{
	nwd=NWD(nwd,tab[i]);
	}
	cout<<"NWD podanych liczb to "<<nwd;
	return 0;
}
