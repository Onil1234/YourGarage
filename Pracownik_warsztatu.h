#pragma once
#include "Osoba.h"

class Pracownik_warsztatu : public Osoba {
	int Etat;
public:
	void Usuwanie_uzytkownika();
	void Wyszukiwanie_klientow();
	void Umowienie_wizyty();
	void Zmiana_terminu_wizyty();
	void Wystawienie_faktury();
	void Aktualizacja_danych_firmy_do_faktury();
	void Stan_naprawy();
	void Odbior_naprawy();
	void Reklamacja_naprawy();
	void Dokonanie_platnosci();
	void Zamawianie_czesci();
	void Anulowanie_zamawiania_czesci();
	void Odbior_zamowionych_czesci();
	void Umiejscowienie_czesci_w_magazynie();
	void Pobieranie_czesci_z_magazynu();

	Pracownik_warsztatu();
	~Pracownik_warsztatu();
};

