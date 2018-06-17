#pragma once
#include "Osoba.h"

class Pracownik_Administarcji : public Osoba {
	int Etat;
public:
	void Usuwanie_uzytkownika();
	void Wyszukiwanie_klientow();
	void Wykonanie_kopii_zapasowej();
	void Aktualizacja_kopii_zapasowej();

	Pracownik_Administarcji();
	~Pracownik_Administarcji();
};

