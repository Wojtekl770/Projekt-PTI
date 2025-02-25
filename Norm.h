#pragma once
#include<iostream>

using namespace std;

class User;
class Norm
{
private:
	/*	Klasa Norm dla danego użytkownika liczy normy spożycia

		energia - średnie zapotrzebowanie w kcal zależne od PAL
		białko - zalecane spożycie w gramach (przekroczenie nie musi dawać ostrzeżenia)
		tłuszcz_min / tluszcz_max - spożycie w gramach, minimalna i maksymalna wartość
		weglowodany - minimalne spożycie w gramach
		cukry - maksymalne spożycie w gramach, po przekroczeniu ostrzeżenie
		błonnik - wystarczające spożycie w gramach
		woda - wystarczające spożycie w mililitrach
		sod - wystarczajace spozycie w miligramach
	*/
	double energia, bialko, tluszcz_min, tluszcz_max, weglowodany,cukry, blonnik, woda, sod, aktywnosc_fizyczna;
public:
	Norm() : energia(0), bialko(0), tluszcz_min(0), tluszcz_max(0), weglowodany(0), cukry(0), blonnik(0), woda(0), sod(0), aktywnosc_fizyczna(0) {}
	Norm(User& some);
	double GetEnergia() { return energia; }
	double GetBialko() { return bialko; }
	double GetTluszczMin() { return tluszcz_min; }
	double GetTluszczMax() { return tluszcz_max; }
	double GetWeglowodany() { return weglowodany; }
	double GetCukry() { return cukry; }
	double GetBlonnik() { return blonnik; }
	double GetWoda() { return woda; }
	double GetSod() { return sod; }
	friend ostream& operator<<(ostream& out, const Norm& some);
	friend class User;
};
