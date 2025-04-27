#include <iostream>
using namespace std;

long long inwersje(int tab[], int temp[], int le, int sr, int pr) 
{
    int inw = 0;

    int i = le;     // pocz¹tek lewej po³owy
    int j = sr + 1;  // pocz¹tek prawej po³owy
    int k = le;     // indeks do tablicy tymczasowej

    while (i <= sr && j <= pr) 
	{
        if (tab[i] <= tab[j]) 
		{
            temp[k++] = tab[i++];
        } else {
            temp[k++] = tab[j++];
            inw += (sr - i + 1);  // inwersje
        }
    }

    while (i <= sr)
	{
		temp[k++] = tab[i++];
	} 
    while (j <= pr) 
	{
		temp[k++] = tab[j++];
	}
    for (int m = le; m <= pr; ++m) 
	{
        tab[m] = temp[m];
    }

    return inw;
}

int sortowanie(int tab[], int temp[], int le, int pr) 
{
    int inw = 0;
    if (le < pr) 
	{
        int sr = le + (pr - le) / 2;
        inw += sortowanie(tab, temp, le, sr);
        inw += sortowanie(tab, temp, sr + 1, pr);
        inw += inwersje(tab, temp, le, sr, pr);
    }
    return inw;
}

int main() {
    int n;
    cout<<"podaj wielkoœæ tablicy"<<endl;
    cin >> n;
    cout<<"podaj wyrazy tablicy"<<endl;
    int tab[n];
	int temp[n];  // tablica pomocnicza 
    for (int i = 0; i < n; ++i) 
	{
        cin >> tab[i];
    }
    for (int i = 0; i < n; ++i) 
	{
        temp[i]=tab[i];
    }
	
    cout<<"iloœæ inwersji w tej tablicy to:"<<sortowanie(tab, temp, 0, n - 1)<< endl;

    return 0;
}
