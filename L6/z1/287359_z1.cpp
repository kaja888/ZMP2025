#include <iostream>

using namespace std; 

class Structure 
{
private:
    int* data;
    int capacity;
    int size;

    void resize(int new_capacity) 
	{
        int* new_data = new int[new_capacity];
        for (int i = 0; i < size; ++i) 
		{
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Structure() : capacity(10), size(0) 
	{
        data = new int[capacity];
    }
    void push_back(int value) 
	{
        if (size == capacity) 
		{
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    int& operator[](int index) 
	{
        return data[index];
    }

    int getSize() const
	{
        return size;
    }

    void print() const 
	{
        for (int i = 0; i < size; ++i) 
		{
            cout << data[i] << " ";
        }
        cout<<endl;
    }
};

// sorrtowanie Bubble Sort
void bubbleSort(Structure& tab,int n) 
{
    bool swapped;
    for (int i = 0; i < n - 1; ++i) 
	{
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) 
		{
            if (tab[j] > tab[j + 1]) 
			{
                swap(tab[j], tab[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // optymalizacja: zakoñcz jeœli ju¿ posortowane
    }
}

int main() 
{
    Structure tab;
    int n, value;

    cout << "Podaj liczbe elementow: ";
    cin >> n;

    cout << "Podaj " << n << " liczb calkowitych:\n";
    for (int i = 0; i < n; ++i) 
	{
        cin >> value;
        tab.push_back(value);
    }

    bubbleSort(tab,n);

    cout << "Posortowane liczby:\n";
    tab.print();

    return 0;
}
