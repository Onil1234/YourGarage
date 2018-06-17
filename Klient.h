#pragma once
#include "Osoba.h"

class Klient : public Osoba {
	string Marka_pojazdu;
	string Data_odbioru;
	int Koszt_naprawy;
public:
	void Umowienie_wizyty();
	void Anulowanie_wizyty();
	void Zmiana_terminu_wizyty();
	void Odbior_naprawy();
	void Reklamacja_naprawy();
	void Dokonanie_platnosci();
	void Wystawnienie_faktury();
	void Aktualizacja_danych_firmy_do_faktury();

	Klient();
	~Klient();
};

