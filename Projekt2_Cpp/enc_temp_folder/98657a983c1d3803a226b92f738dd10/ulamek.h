#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

class UlamekBazowy
{

protected:
    int licznik1, licznik2, mianownik1, mianownik2, dzialanie;
    float wynik;
	bool repeat, zwrocWynik;

public:
	UlamekBazowy() {
		licznik1 = 0;
		mianownik1 = 0;
		licznik2 = 0;
		mianownik2 = 0;
		wynik = 0;
		dzialanie = 0;
		repeat = true;
		zwrocWynik = true;
	}

	virtual void infoOulamkach()=0;
	virtual void infoOdzialaniach()=0;
	virtual void daneLiczbowe()=0;
	virtual void wykonajDzialanie()=0;
	bool getrepeat() {
		bool temp;
		temp = repeat;
		return temp;
	};
	bool getZwrocWynik() {
		bool temp;
		temp = zwrocWynik;
		return temp;
	};
	float getWynik() {
		float wyn;
		wyn = wynik;
		return wyn;
	};

	virtual float add(float, float, float, float)=0;
	virtual float sub(float, float, float, float)=0;
	virtual float mult(float, float, float, float)=0;
	virtual float div(float, float, float, float)=0;
	
	virtual ~UlamekBazowy() { cout << " usuwanie ulamka " << endl; };

};
#endif