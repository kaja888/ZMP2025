#include <iostream>

using namespace std;

int max(int tab[],int n)
{
	int max=tab[1]-tab[0];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int x=tab[j]-tab[i];
			if(x>max)
			{
				max=x;
			}
		}
	}
	return max;
}
int main()
{
	int n;
	cout<<"podaj wielkosc tablicy:"<<endl;
	cin>>n;
	int tab[n];
	cout<<"podaj elementy tablicy:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>tab[i];
	}
	cout<<"maksymalna roznica to:"<<max(tab,n)<<endl;
	return 0;
}
