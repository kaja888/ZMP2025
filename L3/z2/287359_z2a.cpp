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

// Funkcja rekurencyjna do generowania wszystkich podzbiorów
void podzbiory(int i, const int T[], int n, int podzb[], int rozmiar) {
    if (i == n) {
        wypisywanie(podzb, rozmiar);
        return;
    }

    // Dodajemy element T[i] do podzbioru
    podzb[rozmiar] = T[i];
    podzbiory(i + 1, T, n, podzb, rozmiar + 1);

    // Usuwamy element T[i] i generujemy podzbiór bez niego
    podzbiory(i + 1, T, n, podzb, rozmiar);
}

void wszystko(int n, const int T[]) {
    int podzb[n];  // Tablica do przechowywania aktualnego podzbioru
    podzbiory(0, T, n, podzb, 0);
}
int main() {
    int n;
    cout << "Podaj wielkoœæ zbioru: ";
    cin >> n;

    int T[n];
    cout << "Podaj " << n << " liczb ca³kowitych: ";
    for (int i = 0; i < n; i++) 
	{
        cin >> T[i];
    }
	wszystko(n, T); // Wszystkie podzbiory

    return 0;
}
