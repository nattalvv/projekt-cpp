#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

class UlamekBazowy //klasa nadrzêdna 
{

protected:

	int licznik1, licznik2, mianownik1, mianownik2; //dane dla ulamkow
	int dzialanie; //numer operacji
    float wynik; 
	bool repeat, zwrocWynik; //flagi

public:

	UlamekBazowy() { //konstruktor domyslny
		licznik1 = 0;
		mianownik1 = 0;
		licznik2 = 0;
		mianownik2 = 0;
		wynik = 0;
		dzialanie = 0;
		repeat = true;
		zwrocWynik = true;
	}

	//czysto wirtualne funkcje
	virtual void infoOulamkach()=0;
	virtual void infoOdzialaniach()=0;
	virtual void daneLiczbowe()=0;
	virtual void wykonajDzialanie()=0;

	//gettery
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