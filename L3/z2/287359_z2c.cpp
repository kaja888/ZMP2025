#include <iostream>

using namespace std;

// Funkcja pomocnicza do wypisania podzbioru
void wypisywanie(int podzb[], int rozmiar) {
    cout << "{ ";
    for (int i = 0; i <rozmiar; i++) {
        cout << podzb[i] << " ";
    }
    cout << "}" << endl;
}
void podzbioryk(int i,int n,const int T[],int k,int podzb[], int rozmiar) 
{
    if (i == n) 
	{
        if (rozmiar == k) 
		{
            wypisywanie(podzb, rozmiar);
        }
        return;
    }

        // Dodajemy element T[i] do podzbioru
    podzb[rozmiar] = T[i];
    podzbioryk(i + 1,n,T,k,podzb, rozmiar + 1);

        // Usuwamy element T[index] i generujemy podzbiór bez niego
    podzbioryk(i + 1,n,T,k,podzb, rozmiar);
}
void wszystko(int n, const int T[], int k) 
{
    int podzb[n];  // Tablica do przechowywania aktualnego podzbioru
    podzbioryk(0, n, T, k, podzb, 0);
}
int main()
 {
    int n,k;
    cout << "Podaj wielkoœæ zbioru: ";
    cin >> n;
    cout<<"jakiej wielkosci maja byc podzbiory"<<endl;
	cin>>k;
    int T[n];
    cout << "Podaj " << n << " liczb ca³kowitych: ";
    for (int i = 0; i < n; i++) 
	{
        cin >> T[i];
    }
	wszystko(n,T,k); // Wszystkie podzbiory

    return 0;
}
