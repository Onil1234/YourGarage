#pragma once
#include<iostream>
using namespace std;

class Faktury
{
public:
	int ID;
	string nazwa_firmy;
	string NIP;
	string ulica;
	int nr_budynku;
	int nr_lokalu;
	string kod_poczowy;
	string miejscowosc;
	void Wystawienie_faktury();
	void Wydrukuj_fakture();
	void Aktualizacja_danych_firmy_do_faktury();
	Faktury();
	~Faktury();
};

