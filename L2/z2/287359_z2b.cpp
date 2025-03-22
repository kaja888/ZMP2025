#include<iostream>

using namespace std;

int main()
{
	int n;
	int x;
	cout<<"wpisz z ilu liczb będzie składał się twój ciąg"<<endl;
	cin>>n;
	cout<<"podaj liczby ciągu"<<endl;
	int tab[n];
	for(int i=0;i<n;i++)
	{
		cin>>tab[i];
	}
	cout<<"jakiej liczby szukasz w tym ciągu?"<<endl;
	cin>>x;
	int i,j;
	for(j = 0; j < n - 1; j++)
    for(i = 0; i < n - 1; i++)
      if(tab[i]>tab[i+1])
      {
        x = tab[i];
        tab[i]=tab[i+1];
        tab[i+1]=x;
      }
	for(int i=0;i<n;i++)
	{
		if(tab[i]==x)
		{
			cout<<"tak "<<tab[i];
			return 0;
		}
	}
	cout<<"nie";
	return 0;
}