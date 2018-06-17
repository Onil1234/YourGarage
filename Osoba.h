#pragma once
#include<iostream>
using namespace std;

class Osoba {
public:
	Osoba();
	int Id;
	string imie;
	string nazwisko;
	string nr_tel;
	void Dodanie_uzytkownika();
	void Edycja_danych_uzytkownika();
	void Wyswietlanie_danych_klienta();
	~Osoba();
};