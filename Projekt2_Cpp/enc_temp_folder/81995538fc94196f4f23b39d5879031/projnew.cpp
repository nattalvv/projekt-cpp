#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> // Dla std::sort
#include "ulamek.h"

using namespace std;

class Ulamek : public UlamekBazowy {
public:
    virtual void infoOulamkach() override {
        if (zwrocWynik) {
            cout << "Pierwszy ulamek:   \n"; //biblioteka STL
            cout << licznik1 << " / " << mianownik1;
            cout << "\nDrugi ulamek:  \n";
            cout << licznik2 << " / " << mianownik2;
            cout << "\nDzialanie nr:    " << dzialanie << "\n";
            cout << "Wynik = " << wynik << "\n\n";
        }
    }
    virtual void infoOdzialaniach() override {
        cout << "\t\tKalkulator\n";
        cout << "Mozliwe dzialania:\n";
        cout << "1 - Dodawanie \n";
        cout << "2 - Odejmowanie \n";
        cout << "3 - Mnozenie \n";
        cout << "4 - Dzielenie \n";
        cout << "5 - Zakoncz\n\n\n";
    }
    virtual void daneLiczbowe() override {
        cout << "Podaj licznik pierwszego ulamka: ";
        cin >> licznik1;
        cout << "\Podaj mianownik pierwszego ulamka: ";
        cin >> mianownik1;
        while (mianownik1 == 0) {
            cout << "\Mianownik nie moze byc zerem. Podaj inna liczbe: ";
            cin >> mianownik1;
        }
        cout << "Podaj licznik drugiego ulamka: ";
        cin >> licznik2;
        cout << "\Podaj mianownik drugiego ulamka: ";
        cin >> mianownik2;
        while (mianownik2 == 0) {
            cout << "\Mianownik nie moze byc zerem. Podaj inna liczbe: ";
            cin >> mianownik2;
        }
        cout << "\nWybierz nr dzialania: \n";
        cin >> dzialanie;
    }
    virtual void wykonajDzialanie() override {
        switch (dzialanie)
        {
        case 1:
            add(licznik1, mianownik1, licznik2, mianownik2);
            zwrocWynik = true;
            break;
        case 2:
            sub(licznik1, mianownik1, licznik2, mianownik2);
            zwrocWynik = true;
            break;
        case 3:
            mult(licznik1, mianownik1, licznik2, mianownik2);
            zwrocWynik = true;
            break;
        case 4:
            div(licznik1, mianownik1, licznik2, mianownik2);
            zwrocWynik = true;
            break;
        case 5:
            repeat = false;
            zwrocWynik = false;
            break;
        default:
            cout << "Nie istnieje taka operacja. Zacznij od nowa.\n";
            zwrocWynik = false;
        }
    }

    virtual float add(float l1, float m1, float l2, float m2) override {
        wynik = (l1 * m2 + m1 * l2) / (m1 * m2);
        return 0;
    }
    virtual float sub(float l1, float m1, float l2, float m2)  override {
        wynik = (l1 * m2 - m1 * l2) / (m1 * m2);
        return 0;
    }
    virtual float mult(float l1, float m1, float l2, float m2)  override {
        wynik = (l1 / m1) * (l2 / m2);
        return 0;
    }
    virtual float div(float l1, float m1, float l2, float m2)  override {
        if (m1 == 0 || m2 == 0)
            wynik = 0;
        else
            wynik = (l1 / m1) * (m2 / l2);
        return 0;
    }

    virtual ~Ulamek() override { cout << " usuwanie uzytego ulamka" << endl; };
};



int main()
{
    Ulamek *ul = new Ulamek(); //dynamiczna alokacja - na sile
    std::vector<float> wyniki;
    ul->infoOdzialaniach();

    do {
        ul->daneLiczbowe();
        ul->wykonajDzialanie();
        if (ul->getZwrocWynik()) {
            ul->infoOulamkach();
            wyniki.push_back(ul->getWynik());
        }
    } while (ul->getrepeat());

    // U¿ycie algorytmu std::sort do posortowania wyników
    std::sort(wyniki.begin(), wyniki.end());

    // Wypisanie posortowanych wyników
    std::cout << "\nPosortowane wyniki: ";
    for (const auto& wynik : wyniki) {
        std::cout << wynik << " ";
    }
    std::cout << std::endl;

    system("PAUSE");
    delete ul; //unikniecie wyciekow pamieci
    return 0;
}
