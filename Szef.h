#pragma once
#include "Pracownik_Administarcji.h"
#include "Pracownik_warsztatu.h"


class Szef : public Pracownik_Administarcji, Pracownik_warsztatu {
	int Obroty;
public:
	void Wyplata();
	void Zatrudnij_Ppracownika();
	void Zwolnij_pracownika();

	Szef();
	~Szef();
};

