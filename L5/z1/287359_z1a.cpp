#include <iostream>

using namespace std;

int inwersje(int tab[], int n)
{
	int inw=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(tab[i]>tab[j])
			inw++;
		}
	}
	return inw;
}
int main()
{
	int n;
	cout<<"podaj rozmiar tablicy: "<<endl;
	cin>>n;
	int tab[n];
	cout<<"podaj elementy tablicy:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>tab[i];
	}
	cout<<"liczba inwersji w tej tablicy wynosi:"<<inwersje(tab,n)<<endl;
	return 0;
}
