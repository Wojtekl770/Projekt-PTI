#pragma once
#include <iostream>
#include <string>
using namespace std;

class Base {
protected:
	/* Klasy Base, Owoce i Food wykorzystują schemat dziedziczenia, przechowują informacje o wartościach odżywczych danego produktu */
	string nazwa;
	int kcal;
	double tluszcz;
	double weglowodany;
	double blonnik;
	double bialko;
	int index;

public:

	Base(string n, int k, double tl, double we, double bl, double bia, int ind);
	Base() {}
	friend ostream& operator<<(ostream& out, const Base& obj);

	string getname() { return nazwa; }
	int getkcal() { return kcal; }
	double gettluszcz() { return tluszcz; }
	double getweglowodany() { return weglowodany; }
	double getblonnik() { return blonnik; }
	double getbialko() { return bialko; }
	int getindex() { return index; }
	int getindex() const { return index; }

};

class Owoce : public Base {
private:
	double cholesterol; // w mg
	double magnez; // w mg
	double zelazo; // w mg
	double wapn; // w mg
public:
	Owoce(string n, int k, double tl, double cho, double we, double bl, double bia, int ind, double mg, double zel, double wapn);

	double getcholesterol() { return cholesterol; }
	double getmagnez() { return magnez; }
	double getzelazo() { return zelazo; }
	double getwapn() { return wapn; }
};

class Food : public Base {
private:
	double cukry;
	double sol;

	bool alergia_gluten;
	bool alergia_jaja;
	bool alergia_soja;
	bool alergia_nabial;
	bool alergia_orzech;

	bool czy_ma_mieso;
public:
	Food(string n, int k, double tl, double we, double cu, double bl, double bia, int ind, double s, bool gl, bool ja, bool so, bool na, bool orz, bool mies);


	double getcukry() { return cukry; }
	double getsol() { return sol; }
	bool getgluten() { return alergia_gluten; }
	bool getjaja() { return alergia_jaja; }
	bool getsoja() { return alergia_soja; }
	bool getnabial() { return alergia_nabial; }
	bool getorzech() { return alergia_orzech; }
	bool getmieso() { return czy_ma_mieso; }
};

