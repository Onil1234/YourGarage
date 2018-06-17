#include "Pracownik_warsztatu.h"

class Mechanik :public Pracownik_warsztatu {
	int Godziny_w_miesicu;
	int Dni_wolne_wykorzystane;
	int Godziny_pracy;
public:
	void Diagnoza_usterki();

	Mechanik();
	~Mechanik();
};

