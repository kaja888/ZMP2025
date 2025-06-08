#include <iostream>
#include <string>
using namespace std;

class Pojazd 
{
protected:
    string marka;
    string model;
    int rok_produkcji;

public:
    Pojazd(string m, string mo, int rok) : marka(m), model(mo), rok_produkcji(rok) {}

	void wyswietl()  
	{
        cout << "Marka: " << marka
             << ", Model: " << model
             << ", Rok produkcji: " << rok_produkcji;
    }

};

class Samochod : public Pojazd 
{
private:
    int liczba_drzwi;

public:
    Samochod(string m, string mo, int rok, int drzwi)
        : Pojazd(m, mo, rok), liczba_drzwi(drzwi) {}

    void wyswietl() 
	{
        cout << "Samochod -> ";
        Pojazd::wyswietl();
        cout << ", Liczba drzwi: " << liczba_drzwi << endl;
    }
};

class Rower : public Pojazd 
{
private:
    int liczba_przerzutek;

public:
    Rower(string m, string mo, int rok, int przerzutki)
        : Pojazd(m, mo, rok), liczba_przerzutek(przerzutki) {}

    void wyswietl() 
	{
        cout << "Rower -> ";
        Pojazd::wyswietl();
        cout << ", Liczba przerzutek: " << liczba_przerzutek << endl;
    }
};

int main()
 {
    string marka_sam, model_sam, marka_row, model_row;
    int rok_sam, drzwi, rok_row, przerzutki;

    cout << "Podaj dane samochodu (marka model rok drzwi): ";
    cin >> marka_sam >> model_sam >> rok_sam >> drzwi;

    cout << "Podaj dane roweru (marka model rok przerzutki): ";
    cin >> marka_row >> model_row >> rok_row >> przerzutki;

    Samochod samochod(marka_sam, model_sam, rok_sam, drzwi);
    Rower rower(marka_row, model_row, rok_row, przerzutki);

    cout << "\n=== Informacje o pojazdach ===" << endl;
    samochod.wyswietl();
    rower.wyswietl();

    return 0;
}

