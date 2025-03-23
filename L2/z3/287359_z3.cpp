#include<iostream>

using namespace std;

int main()
{
	int sekr[8],wiad[8],zasz[8];
	cout<<"podaj sekret ktorym bedziesz szyfrowac(8 cyfr, 0 albo 1)"<<endl;
	for(int i=0;i<8;i++)
	{
		cin>>sekr[i];
	}
	cout<<"podaj wiadomosc do zaszyfrowania"<<endl;
	for(int i=0;i<8;i++)
	{
		cin>>wiad[i];
	}
	for(int i=0;i<8;i++)
	{
		zasz[i]=sekr[i]^wiad[i];
	}
	cout<<"zaszyfrowana wiadomosc to:"<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<zasz[i];
	}
	return 0;
}
