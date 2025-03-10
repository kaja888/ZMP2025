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
	int x;
	int n=1;
	int l=0;
	int m=1;
	int s=0;
	cout<<"podaj liczbę naturalną, nie 0"<<endl;
	cin>>x;
	while(m<x)
	{
		if(x%m==0)
		{
			while(n<x)
			{
				if(NWD(n,x)==1)
				{
						l++;
				}
				n++;
			}	
		s=s+l;
		}
		m++;
	}
	cout<<s;
	
	
	return 0;
}