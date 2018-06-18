#include<iostream>
#include<fstream>
#include<string>
#include"Osoba.h"
#include"Wizyty.h"
#include"Administartor_systemu.h"
#include"Klient.h"
#include"Klient_premium.h"
#include"Mechanik.h"
#include"Pracownik_Administarcji.h"
#include"Pracownik_warsztatu.h"
#include"Szef.h"
#include"Faktury.h"

using namespace std;

int user;
void opcje_admin();
void opcje_klient();
void opcje_szef();
void opcje_mechanik();
int logowanie();
void User(int user);
string username;

Wizyty *wizyta = new Wizyty;
Klient *klient = new Klient;
Klient_premium *klientp = new Klient_premium;
Faktury *faktura = new Faktury;

int login()
{
	string login, haslo, k;
	fstream Konta;
	bool i = false;
	int ID;
system_login:
	cout << "podaj login: ";
	cin >> login;
	cout << "poaj haslo: ";
	cin >> haslo;

	Konta.open("resources/logowanie.txt", ios::in);

	while (getline(Konta, k))
	{
		if (login == k)
		{

			getline(Konta, k);
			if (k == haslo)
			{
				cout << "zostales zalogowany jako: " << login << endl;
				getline(Konta, k);
				ID = atoi(k.c_str());
				return ID;

			}
			else
			{
				login = "0";
			}
		}
	}
	cout << "Wpisales nieprawodlowe dane!" << endl;
	Konta.close();
	goto system_login;
}

void opcje_admin() {
	int wybor = 0;
wybor:
	wybor = 0;
	cout << " Wybierz opcje:" << endl;
	cout << "1. Pokaz umowiona wizyte" << endl;
	cout << "2. Dodaj Klienta" << endl;
	cout << "4. Wyloguj" << endl;
	cout << "5. Koniec programu" << endl;
	cin >> wybor;
	switch (wybor) {
	case 1: {
		if (wizyta->nr_wizyty == 1) {
			cout << "Numer wizyty: " << wizyta->nr_wizyty << endl;
			cout << "Data wizyty: " << wizyta->dzien << "." << wizyta->miesiac << "." << wizyta->rok << endl;
			cout << "Premium: "; if (wizyta->premium == 1) cout << "tak"; else cout << "nie";
			cout << endl << "Problem z samochodem marki " << wizyta->marka << ", model " << wizyta->model << endl;
			cout << "Podany opis problemu: " << wizyta->problem << endl;


			goto wybor;
		}
		else {
			cout << "Brak wizyt!" << endl;
			goto wybor;
		}

	}break;
	case 2:
	{
		int i = 1;
		klient->Id = i;
		cout << endl << "Podaj Imie: ";
		cin >> klient->imie;
		cout << endl << "Podaj Nazwisko: ";
		cin >> klient->nazwisko;
		cout << endl << "Podaj numer telefonu: ";
		cin >> klient->nr_tel;
		premium:
		cout << endl << "Uzytkownik premium? 1 - tak, 0 - nie" << endl;
		cin >> klientp->Premium_aktywne;
		if (!(klientp->Premium_aktywne == 1 || klientp->Premium_aktywne == 0)) {
			cout << "Wybrales zla opcje!" << endl;
			goto premium;
		}
		
		/*fstream logowanie;
		string linia;
		int k = 0;
		logowanie.open("resources/logowanie.txt", ios::in);

		while (getline(logowanie, linia))
		{
			k++;
		}

		logowanie.open("resources/logowanie.txt", ios::out | ios::app);

		logowanie << klient->imie << endl;
		logowanie << klient->nazwisko << endl;
		logowanie << klient->nr_tel << endl;
		klient->Id = k / 4;
		logowanie << klient->Id << endl;
		logowanie.close(); */

		goto wybor;
	}break;
	case 4:
	{
		User(login());
	}break;
	case 5:
	{
		system("pause");
	}break;
	}
}


void opcje_szef() {
	int wybor = 0;
wybor:
	wybor = 0;
	cout << " Wybierz opcje:" << endl;
	cout << "1. Pokaz umowiona wizyte" << endl;
	cout << "2. Dodaj Klienta" << endl;
	cout << "4. Wyloguj" << endl;
	cout << "5. Koniec programu" << endl;
	cin >> wybor;
	switch (wybor) {
	case 1: {
		if (wizyta->nr_wizyty == 1) {
			cout << "Numer wizyty: " << wizyta->nr_wizyty << endl;
			cout << "Data wizyty: " << wizyta->dzien << "." << wizyta->miesiac << "." << wizyta->rok << endl;
			cout << "Premium: "; if (wizyta->premium == 1) cout << "tak"; else cout << "nie";
			cout << endl << "Problem z samochodem marki " << wizyta->marka << ", model " << wizyta->model << endl;
			cout << "Podany opis problemu: " << wizyta->problem << endl;
			goto wybor;
		}
		else {
			cout << "Brak wizyt!" << endl;
			goto wybor;
		}

	}break;
	case 2:
	{
		int i = 1;
		klient->Id = i;
		cout << endl << "Podaj Imie: ";
		cin >> klient->imie;
		cout << endl << "Podaj Nazwisko: ";
		cin >> klient->nazwisko;
		cout << endl << "Podaj numer telefonu: ";
		cin >> klient->nr_tel;
	premium:
		cout << endl << "Uzytkownik premium? 1 - tak, 0 - nie";
		cin >> klientp->Premium_aktywne;
		if (!(klientp->Premium_aktywne == 1 || klientp->Premium_aktywne == 0)) {
			cout << "Wybrales zla opcje!" << endl;
			goto premium;
		}
		goto wybor;
	}break;
	case 4:
	{
		User(login());
	}break;
	case 5:
	{
		system("pause");
	}break;
	}




}

void opcje_mechanik() {
	int wybor = 0;
wybor:
	wybor = 0;
	cout << " Wybierz opcje:" << endl;
	cout << "1. Pokaz umowiona wizyte" << endl;
	cout << "2. Dodaj Klienta" << endl;
	cout << "3. Wystaw fakture" << endl;
	cout << "4. Wyloguj" << endl;
	cout << "5. Koniec programu" << endl;
	cin >> wybor;
	switch (wybor) {
	case 1: {
		if (wizyta->nr_wizyty == 1) {
			cout << "Numer wizyty: " << wizyta->nr_wizyty << endl;
			cout << "Data wizyty: " << wizyta->dzien << "." << wizyta->miesiac << "." << wizyta->rok << endl;
			cout << "Premium: "; if (wizyta->premium == 1) cout << "tak"; else cout << "nie";
			cout << endl << "Problem z samochodem marki " << wizyta->marka << ", model " << wizyta->model << endl;
			cout << "Podany opis problemu: " << wizyta->problem << endl;
			goto wybor;
		}
		else {
			cout << "Brak wizyt!" << endl;
			goto wybor;
		}

	}break;
	case 2:
	{
		int i = 1;
		klient->Id = i;
		cout << endl << "Podaj Imie: ";
		cin >> klient->imie;
		cout << endl << "Podaj Nazwisko: ";
		cin >> klient->nazwisko;
		cout << endl << "Podaj numer telefonu: ";
		cin >> klient->nr_tel;
	premium:
		cout << endl << "Uzytkownik premium? 1 - tak, 0 - nie";
		cin >> klientp->Premium_aktywne;
		if (!(klientp->Premium_aktywne == 1 || klientp->Premium_aktywne == 0)) {
			cout << "Wybrales zla opcje!" << endl;
			goto premium;
		}
		goto wybor;

	}break;
	case 3: {
		cout << "Podaj nazwe firmy: ";
		cin >> faktura->nazwa_firmy;
		faktura:
		cout << endl << "Podaj NIP: ";
		cin >> faktura->NIP;
		if (faktura->NIP.length() <= 0 || faktura->NIP.length() >= 11) {
			cout << "Poda³es zly numer NIP";
			goto faktura;
		}
		cout << endl << "Podaj ulice: ";
		cin >> faktura->ulica;
		cout << endl << "Podaj numer budynku: ";
		cin >> faktura->nr_budynku;
		cout << endl << "Podaj numer lokalu: ";
		cin >> faktura->nr_lokalu;
		cout << endl << "Podaj kod pocztowy: ";
		cin >> faktura->kod_poczowy;
		cout << endl << "Podaj miejscowosc:";
		cin >> faktura->miejscowosc;
		cout << endl << "Faktura zostala dodana!";
		goto wybor;

	}break;
	case 4:
	{
		User(login());
	}break;
	case 5:
	{
		system("pause");
	}break;
	}
}

void opcje_klient() {
	

wybor:
	int wybor=0;
	//wizyta->nr_wizyty = 1;
	cout << " Wybierz opcje:" << endl;
	cout << "1. Umow wizyte" << endl;
	cout << "2. Pokaz umowiona wizyte" << endl;
	cout << "3. Faktury" << endl;
	cout << "4. Wyloguj" << endl;
	cout << "5. Koniec programu" << endl;
	cin >> wybor;
	switch (wybor) {
		case 1: {
			wizyta->nr_wizyty=1;
			cout << "*****Umow wizyte*****" << endl;
			cout << "Podaj date w formie DD.MM.RRRR" << endl;
			dzien:
			cout << "Podaj dzien: ";
			cin >> wizyta->dzien;
			if (wizyta->dzien <= 0 || wizyta->dzien > 31) {
				cout << "Nieprawidlowy dzien!" << endl;
				goto dzien;
			}

			miesiac:
			cout << endl << "Podaj miesiac: ";
			cin >> wizyta->miesiac;
			if (wizyta->miesiac <= 0 || wizyta->miesiac >12) {
				cout << "Nieprawidlowy miesiac!";
				goto miesiac;
			}

			rok:
			cout << endl << "Podaj rok: ";
			cin >> wizyta->rok;
			if (wizyta->rok <= 2017 || wizyta->rok >2020) {
				cout << "Nieprawidlowy rok!";
				goto rok;
			}
			premium:
			cout << endl << "Chcesz byc klientem premium? (+50% podstawowej ceny). Wybierz 1 - tak, 0 - nie:";
			cin >> wizyta->premium;
			if (!(wizyta->premium == 1 || wizyta->premium == 0)) {
				cout << "Wybrales zla opcje!" << endl;
				goto premium;
			}
			cout << endl << "Podaj marke samochodu: ";
			cin >> wizyta->marka;
			cout << endl << "Podaj model samochodu: ";
			cin >> wizyta->model;
			cout << endl << "Krotki opis problemu: ";
			cin >> wizyta->problem;
			cout << endl << "Zostales umowiony na wizyte!" << endl;
			
			fstream wizyty;
			wizyty.open("resources/Wizyty.txt", ios::out | ios::app);
			wizyty << wizyta->dzien << endl;
			wizyty << wizyta->miesiac << endl;
			wizyty << wizyta->rok << endl;
			wizyty << wizyta->premium << endl;
			wizyty << wizyta->marka << endl;
			wizyty << wizyta->model << endl;
			wizyty << wizyta->problem << endl;
			//wizyty.close();

			goto wybor;
		}break;
		
		case 2: {
			if (wizyta->nr_wizyty == 1) {
				cout << "Numer wizyty: " << wizyta->nr_wizyty << endl;
				cout << "Data wizyty: " << wizyta->dzien << "." << wizyta->miesiac << "." << wizyta->rok << endl;
				cout << "Premium: "; if (wizyta->premium == 1) cout << "tak"; else cout << "nie";
				cout << endl << "Problem z samochodem marki " << wizyta->marka << ", model " << wizyta->model << endl;
				cout << "Podany opis problemu: " << wizyta->problem << endl;
				goto wybor;
			}
			else {
				cout << "Brak wizyt!" << endl;
				goto wybor;
			}

		}break;
		
		case 3: {
			cout << "Brak faktur!" << endl;
			goto wybor;
		}break;
		
		case 4:
		{
			User(login());
		}break;
		case 5: 
		{
			system("pause");
		}break;
	}
}

int logowanie() {
	
	string password;
	logowanie:
	username.clear();
	password.clear();
	cout << "Podaj login: ";
	
	cin >> username;

	if (username == "1") {
		system("pause");
	}

	cout << "Podaj haslo: ";
	cin >> password;

	if ( username == "Admin" && password == "123" ) {
		cout << "Zostales zalogowny jako Administrator!" << endl;
		return user = 1;
	}
	else if (username == "Szef" && password == "zaq") {
		cout << "Zostales zalogowny jako Szef!" << endl;
		return user = 2;
	}
	else if (username == "Mechanik" && password == "qwerty") {
		cout << "Zostales zalogowny jako Mechanik!" << endl;
		return user = 3;
	}
	else if (username == "Klient" && password == "wsad") {
		cout << "Zostales zalogowny jako Klient!" << endl;
		return user = 4;
	}
	else {
		cout << "Wpisales nieprawodlowe dane!" << endl;
		goto logowanie;
	}
}



void User(int user) {
	switch (user) {
		case 1: {
			//Admin
			Osoba * admin = new Osoba;
			admin->Id = 001;
			//cout << admin->Id;
			opcje_admin();
		
		}break;

		case 2: {
			//Szef
			Osoba * szef = new Osoba;
			szef->Id = 002;
			//cout << szef->Id;
			opcje_szef();
		
		}break;

		case 3: {
			//Mechanik
			Osoba * mechanik = new Osoba;
			mechanik->Id = 003;
			//cout << mechanik->Id;
			opcje_mechanik();
		
		}break;

		case 4: {
			//Klient
			Osoba * klient = new Osoba;
			klient->Id = 004;
			opcje_klient();
			//cout << klient->Id;
		
		}break;


	}
}

int main() {
	cout << "Wersja systemu: Pre-alpha 0.9" << endl << endl;
	cout << "Witamy w YourGarage!" << endl;
	cout << "Zaloguj sie lub nacisnij 1. by wyjsc" << endl;
		
	//user = logowanie();
	
	user = login();
	User(user);

	system("pause");
}