#pragma once
#include <string>
#include<iostream>
using namespace std;
class Wizyty
{
public:
	Wizyty();
	int nr_wizyty;
	int dzien;
	int miesiac;
	int rok;
	string marka;
	string model;
	string problem;
	short premium;

	~Wizyty();
};

