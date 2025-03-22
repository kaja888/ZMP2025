#include<iostream>

using namespace std;

int main()
{
	int x;
	int l=1;
	
	cout<<"podaj liczbÄ™ naturalnÄ…"<<endl;
	cin>>x;
	while(x!=1)
	{
		l++;
		if(x%2==0)
		{
			x=x/2;
			cout<<x<<", ";
		}
		else
		{
			x=3*x+1;
			cout<<x<<", ";
		}	
	}	
	cout<<"dĹ‚ugoĹ›Ä‡ trajektori dla"<<x<<"to:"<<l;
	return 0;
}
