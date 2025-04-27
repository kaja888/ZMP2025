#include <iostream>
#include <algorithm>

using namespace std;

// Funkcja scalaj¹ca dwa posortowane fragmenty tablicy
void merge(int tab[], int temp[], int le, int sr, int pr) 
{
    int i = le;     // pocz¹tek lewej czêœci
    int j = sr + 1;  // pocz¹tek prawej czêœci
    int k = le;     // wskaŸnik do tablicy tymczasowej

    while (i <= sr && j <= pr) 
	{
        if (tab[i] <= tab[j]) 
		{
            temp[k++] = tab[i++];
        } else {
            temp[k++] = tab[j++];
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
    for (int l = le; l <= pr; ++l) 
	{
        tab[l] = temp[l];
    }
}

void mergeSort(int temp[],int tab[], int n) 
{
    for (int s= 1;  s< n; s*= 2) 
	{
        for (int i = 0; i < n; i += 2 * s) 
		{
            int le = i;
            int sr = min(i + s - 1, n - 1);
            int pr = min(i + 2 * s - 1, n - 1);

            if (sr < pr) { // tylko jeœli jest co scalaæ
                merge(tab, temp, le, sr, pr);
            }
        }
    }

}

int main() 
{
    int n;
	cout<<"podaj wielkosc tablicy"<<endl;
    cin >> n;
    int tab[n];
    cout<<"podaje elementy tablicy"<<endl;
    for (int i = 0; i < n; ++i) 
	{
        cin >> tab[i];
    }
    int temp[n];
    for (int i = 0; i < n; ++i) 
	{
        temp[i]=tab[i];
    }

    mergeSort(temp,tab, n);

    for (int i = 0; i < n; ++i) 
	{
        cout << tab[i] <<"  ";
	}
    return 0;
}
