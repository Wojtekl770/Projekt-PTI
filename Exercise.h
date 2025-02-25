#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class Exercise
{
	/* Klasa umożliwiająca użytkownikowi wpisywanie ćwiczeń i przechowująca dane o nich */
	float time;
	int kcal;
	string nazwa;
	string date;

public:
	Exercise(float time=0, int kcal=0, string nazwa=" ") : time(time), kcal(kcal), nazwa(nazwa) {
		char d[9];
		_strdate_s(d);
		date.assign(d);
		for (int i = 0; i < 9; i++) {
			if (date[i] == '/') date[i] = '_';
		}
	}
	void NewEx();
	float GetTime() { return time; }
	int GetKcal() { return kcal; }
	string GetNazwa() { return nazwa; }
	friend ostream& operator<<(ostream& out, const Exercise& ex);
	friend void AddToFile(const Exercise& ex);
};

