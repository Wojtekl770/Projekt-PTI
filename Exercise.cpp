#include "Exercise.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

ostream& operator<<(ostream& out, const Exercise& ex)
{
	out << "Nazwa cwiczenia: " << ex.nazwa << endl;
	if (ex.time == 0) out << "nieznany czas wykonywania cwiczenia" << endl;
	else out << "czas wykonywania cwiczenia: " << ex.time << " minut" << endl;
	if (ex.kcal == 0) out << "nieznana ilosc spalanych kalorii" << endl;
	if (ex.kcal != 0 && ex.time != 0) out << "spalone kcal: " << ex.kcal << endl;
	return out;
}


void Exercise::NewEx()
{
	cout << "Podaj nazwe cwiczenia: ";
	cin.ignore();
	getline(cin, nazwa);
	cout << "Podaj czas wykonywania cwiczenia (w minutach): ";
	cin >> time;
	cout << "Podaj ilosc spalonych kilokalorii (jesli nie wiesz, wpisz 0): ";
	cin >> kcal;
	AddToFile(*this);
}

void AddToFile(const Exercise& ex)
{
	fstream ExFile;
	string file_name = ex.date + ".txt";
	ExFile.open(file_name, ios_base::app);
	ExFile << ex << endl;
	ExFile.close();
}