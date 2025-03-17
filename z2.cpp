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