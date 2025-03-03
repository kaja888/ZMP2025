#include<iostream>
 using namespace std;
 
int main()
{
 int x=1;
 int y=2;
 int z=3;
 y=x=z;/* to działa w taki sposób, że przypisuje wszystkim zmiennym przed 
 ostatnią wartość tej ostatniej zmiennej czyli w tym przypadku zmiennym y i x przypisze
 wartość zmiennej z*/
 cout<<"x="<<x<<endl;
 cout<<"y="<<y<<endl;
 cout<<"z="<<z<<endl;
 return 0;
}
