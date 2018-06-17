#include "Pracownik_Administarcji.h"

class Administartor_systemu : public Pracownik_Administarcji {
	int Bonus_do_wyplaty;
public:
	void Naprawa_sprzetu();
	void Aktualizacja_sprzetu();
	void Konfiguracja_sprzetu();

	Administartor_systemu();
	~Administartor_systemu();
};

