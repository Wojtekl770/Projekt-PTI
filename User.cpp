#include "User.h"
#include <math.h>
#include<iostream>
#include<fstream>
#include <ctime>
#include<Windows.h>
#include <string.h>
int User::ilosc_alergi = 0;
using std::cout;
using std::cin;
using std::endl;

User::User()
{
	HANDLE  hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string motto = " Zdrowe zywienie to podstawa ";

	cout << "Podaj imie: " << endl;
	cin >> imie;
	cout << "Podaj plec(M/K): " << endl;
	char p;
	cin >> p;
	while (!(p == 'M') && !(p == 'K'))
	{
		cout << "Niepoprawna plec. Prosze wpisac ponownie" << endl;
		cin >> p;
	}
	SetPlec(p);
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	for (int i = 0; i < 120; i++)
	{
		if (i >= 46 && i < 75)
			cout << motto.at(i - 46);
		else
			cout << '*';
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);

	cout << "Podaj wage(w kg): " << endl;
	float w;
	cin >> w;
	while (w < 0 || w > 610)
	{
		cout << "Niepoprawna waga. Prosze wpisac ponownie" << endl;
		cin >> w;
	}
	SetWeight(w);
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	for (int i = 0; i < 120; i++)
	{
		if (i >= 46 && i < 75)
			cout << motto.at(i - 46);
		else
			cout << '*';
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);

	cout << "Podaj wzrost(w centymetrach): " << endl;
	float h;
	cin >> h;
	while (h < 40 || h > 400)
	{
		cout << "Niepoprawny wzrost. Prosze wpisac ponownie" << endl;
		cin >> h;
	}
	h = h/100;
	SetHeight(h);
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	for (int i = 0; i < 120; i++)
	{
		if (i >= 46 && i < 75)
			cout << motto.at(i - 46);
		else
			cout << '*';
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	SetHeight(h);
	SetBMI(w / (h * h));

	cout << "Podaj wiek: " << endl;
	int  a;
	cin >> a;
	while (a < 0 || a > 150)
	{
		cout << "Niepoprawny wiek. Prosze wpisac ponownie" << endl;
		cin >> a;
	}
	SetAge(a);
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	for (int i = 0; i < 120; i++)
	{
		if (i >= 46 && i < 75)
			cout << motto.at(i - 46);
		else
			cout << '*';
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);



	cout << "czy posiadasz jakies alergie?(t/n)" << endl;
	char k;
	cin >> k;
	while (!(k == 't') && !(k == 'n'))
	{
		cout << "Niepoprawna odpowiedz. Prosze wpisac ponownie" << endl;
		cin >> k;
	}
	std::string alerg;
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	for (int i = 0; i < 120; i++)
	{
		if (i >= 46 && i < 75)
			cout << motto.at(i - 46);
		else
			cout << '*';
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	gluten = 0, jaja = 0, soja = 0, nabial = 0, orzech = 0;
	while (k == 't')
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 11);
		for (int i = 0; i < 120; i++)
		{
			if (i >= 46 && i < 75)
				cout << motto.at(i - 46);
			else
				cout << '*';
		}
		cout << endl;
		SetConsoleTextAttribute(hConsole, 15);
		ilosc_alergi++;
		std::cout << "Wpisz swoja alergie: " << endl;
		cout << "gluten:";
		if (gluten == 1) cout << " X";
		cout << endl;
		cout << "jaja:";
		if (jaja == 1) cout << " X";
		cout << endl;
		cout << "soja";
		if (soja == 1) cout << " X";
		cout << endl;
		cout << "nabial:";
		if (nabial == 1) cout << " X";
		cout << endl;
		cout << "orzech:";
		if (orzech == 1) cout << " X";
		cout << endl;
		cin >> alerg;
		while (alerg != "gluten" && alerg != "jaja" && alerg != "soja" && alerg != "nabial" && alerg != "orzech")
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			for (int i = 0; i < 120; i++)
			{
				if (i >= 46 && i < 75)
					cout << motto.at(i - 46);
				else
					cout << '*';
			}
			cout << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Niepoprawna odpowiedz. Prosze wpisac ponownie" << endl;
			std::cout << "Wpisz swoja alergie: " << endl;
			cout << "Gluten:";
			if (gluten == 1) cout << " X";
			cout << endl;
			cout << "Jaja:";
			if (jaja == 1) cout << " X";
			cout << endl;
			cout << "Soja";
			if (soja == 1) cout << " X";
			cout << endl;
			cout << "Nabial:";
			if (nabial == 1) cout << " X";
			cout << endl;
			cout << "Orzech:";
			if (orzech == 1) cout << " X";
			cout << endl;
			cin >> alerg;
		}
		if (alerg == "gluten") gluten = 1;
		if (alerg == "jaja") jaja = 1;
		if (alerg == "soja") soja = 1;
		if (alerg == "nabial") nabial = 1;
		if (alerg == "orzech") orzech = 1;
		//cout << gluten << jaja << soja << nabial << orzech << endl; // Sprawdzanie
		User::SetAlergie(alerg);
		system("cls");
		SetConsoleTextAttribute(hConsole, 11);
		for (int i = 0; i < 120; i++)
		{
			if (i >= 46 && i < 75)
				cout << motto.at(i - 46);
			else
				cout << '*';
		}
		cout << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Czy posiadasz jeszcze jakas alergie?(t/n)" << endl;    // tu jest problem ze spacjami 
		cin >> k;
		while (!(k == 't') && !(k == 'n'))
		{
			cout << "Niepoprawna odpowiedz. Prosze wpisac ponownie" << endl;
			cin >> k;
		}
	}
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	for (int i = 0; i < 120; i++)
	{
		if (i >= 46 && i < 75)
			cout << motto.at(i - 46);
		else
			cout << '*';
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);


	cout << "Jaki masz styl zycia?" << endl << "1. praca siedzaca , brak cwiczen" << endl << "2. praca siedzaca, lekka aktywnosc w ciagu tygodnia" << endl
		<< "3. praca siedzaca, regularne treningi w ciagu tygodnia" << endl << "4. regularne, czeste i wymagajace treningi" << endl << "5. sport zawodowy" << endl;
	cin >> a;
	while (a < 1 || a > 5)
	{
		cout << "Niepoprawna odpowiedz. Prosze wpisac ponownie" << endl;
		cin >> a;
	}
	switch (a)
	{
	case 1: PAL = 1.2; break;
	case 2: PAL = 1.4; break;
	case 3: PAL = 1.6; break;
	case 4: PAL = 1.8; break;
	case 5: PAL = 2; break;
	}
	this->norma = Norm(*this);
}

User::User(float weight, float height, float BMI, float PAL, int age, char plec, string imie, bool gluten, bool jaja, bool soja, bool nabial, bool orzech): weight(weight), height(height), BMI(BMI), PAL(PAL), age(age), plec(plec), imie(imie), gluten(gluten), jaja(jaja), soja(soja), nabial(nabial), orzech(orzech)
{
	norma = Norm(*this);
	int i = 0;
	if (gluten)
	{
		alergie[i] = "gluten";
		i++;
	}
	if (jaja)
	{
		alergie[i] = "jaja";
		i++;
	}
	if (soja)
	{
		alergie[i] = "soja";
		i++;
	}
	if (nabial)
	{
		alergie[i] = "nabial";
		i++;
	}
	if (orzech)
	{
		alergie[i] = "orzech";
		i++;
	}
	User::ilosc_alergi = i+1;
}
void User::GetAlergie()
{
	cout << "alergie: " << endl;
	for (int i = 0; i < ilosc_alergi; i++) cout << i << ". " << alergie[i] << endl;
}

void User::SetAlergie(std::string alergia)
{
	if (ilosc_alergi > 0)
	{
		std::string* tmp = new(std::nothrow) std::string[ilosc_alergi - 1];
		for (int i = 0; i < ilosc_alergi - 1; i++)
		{
			tmp[i] = alergie[i];
		}
		delete[] this->alergie;
		this->alergie = new (std::nothrow) std::string[ilosc_alergi];
		for (int i = 0; i < ilosc_alergi - 1; i++)
		{
			alergie[i] = tmp[i];
		}
		delete[] tmp;
		this->alergie[ilosc_alergi - 1] = alergia;
		return;
	}
	this->alergie = new (std::nothrow) std::string;
	this->alergie[0] = alergia;
}

void User::SetDiet()
{
	cout << "Twoja dieta to: " << endl << "1. zwykla" << endl << " 2. redukcyjna";
	int k;
	cin >> k;
	if (k == 1) this->diet = "zwykla";
	else if (k == 2) this->diet = "redukcyjna";
}
