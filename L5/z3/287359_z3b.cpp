#include <iostream>
#include <algorithm>

using namespace std;

int max(int tab[],int n)
{
	int sr=n/2;
	int max_l=tab[0];
	int min_l=tab [0];
	for(int i=1;i<sr;i++)
	{
		min_l=min(min_l,tab[i]);
		max_l=max(max_l,tab[i]);
	}
	int min_p=tab[sr];
	int max_p=tab[sr];
	for(int i=sr+1;i<n;i++)
	{
		min_p=min(min_p,tab[i]);
		max_p=max(max_p,tab[i]);
	}
	int Max_l=max_l-min_l;
	int Max_p=max_p-min_p;
	int x=max_p-min_l;
	int q=max_l-min_p;
	return max({Max_l,Max_p,x,q});
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
