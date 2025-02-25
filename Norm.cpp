#include<math.h>
#include"User.h"
#include"Norm.h"



ostream& operator<<(ostream& out, const Norm& some)
{
	//bialko, tluszcz_min, tluszcz_max, weglowodany, blonnik, woda, sod, aktywnosc_fizyczna;
	out << " Normy dzienne: " << endl;
	out << "1. Energia: " << some.energia << " kcal" << endl;
	out << "2. Bialko: " << some.bialko <<" g " << endl;
	out << "3. Tluszcze (wartosc minimalna, wartosc maksymalna): " << some.tluszcz_min << " g, " << some.tluszcz_max <<" g"<< endl;
	out << "4. Weglowodany: " << some.weglowodany << " g"<<endl;
	out << "5. Cukry: " << some.cukry <<" g "<< endl;
	out << "6. Blonnik: " << some.blonnik << " g " << endl;
	out << "7. Woda: " << some.woda << " ml " << endl;
	out << "8. Sod: " << some.sod << " mg " << endl;
	out << "9. Aktywnosc fizyczna: " << some.aktywnosc_fizyczna << " minut " << endl;
	return out;
}

Norm::Norm (User& some)
{
	double eps = 1e-6;
	//Ustawienie wartości dla większości grup, przy ewentualnych różnicach wartość jest zmieniana
	weglowodany = 130;
	bialko = 0.9 * some.GetWeight();
	cukry = 60;
	sod = 1500;
	if (some.GetPlec() == 'M') woda = 2500;
	else //(some.GetPlec() == 'K') 
		woda = 2000;

	// Wyznaczenie zapotrzebowania energetycznego
	if (some.GetAge() >= 16 && some.GetAge() <= 18)
	{
		blonnik = 21;
		if (some.GetPlec() == 'M')
		{ ///Dla wagi +-67kg
			bialko = 0.95 * some.GetWeight(); //gram
			if (abs(some.GetPAL() - 1.2) < eps)
			{
				energia = 2360;
				tluszcz_min = 52.6;
				tluszcz_max = 93;
			}
			if (abs(some.GetPAL() - 1.4) < eps)
			{
				energia = 2680;
				tluszcz_min = 59.8;
				tluszcz_max = 105;
			}
			if (abs(some.GetPAL() - 1.6) < eps)
			{
				energia = 3000;
				tluszcz_min = 67;
				tluszcz_max = 117;

			}
			if (abs(some.GetPAL() - 1.8) < eps)
			{
				energia = 3320;
				tluszcz_min = 74.2;
				tluszcz_max = 129;
			}
			if (abs(some.GetPAL() - 2.0) < eps)
			{
				energia = 3700;
				tluszcz_min = 82.5;
				tluszcz_max = 144;
			}
		}
		if (some.GetPlec() == 'K')
		{
			//waga +-57kg
			bialko = 0.95 * some.GetWeight(); //gram

			if (abs(some.GetPAL() - 1.2) < eps)
			{
				energia = 1730;
				tluszcz_min = 38.4;
				tluszcz_max = 68.4;
			}
			if (abs(some.GetPAL() - 1.4) < eps)
			{
				energia = 2010;
				tluszcz_min = 44.8;
				tluszcz_max = 78.8;
			}
			if (abs(some.GetPAL() - 1.6) < eps)
			{
				energia = 2150;
				tluszcz_min = 51.2;
				tluszcz_max = 89.2;
			}
			if (abs(some.GetPAL() - 1.8) < eps)
			{
				energia = 2570;
				tluszcz_min = 57.4;
				tluszcz_max = 99.2;
			}
			if (abs(some.GetPAL() - 2.0) < eps)
			{
				energia = 2850;
				tluszcz_min = 63;
				tluszcz_max = 111;
			}
		}

	}
	else if (some.GetAge() >= 19 && some.GetAge() <= 30)
	{
		blonnik = 30;
		if (some.GetPlec() == 'M')
		{

			if (some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1750;
					tluszcz_min = 40;
					tluszcz_max = 69;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2100;
					tluszcz_min = 47;
					tluszcz_max = 82;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2450;
					tluszcz_min = 54;
					tluszcz_max = 95;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2730;
					tluszcz_min = 60.8;
					tluszcz_max = 106.2;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3050;
					tluszcz_min = 68;
					tluszcz_max = 119;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 2050;
					tluszcz_min = 45;
					tluszcz_max = 79;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2350;
					tluszcz_min = 52;
					tluszcz_max = 91;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2650;
					tluszcz_min = 59;
					tluszcz_max = 103;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2990;
					tluszcz_min = 66;
					tluszcz_max = 116.4;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3350;
					tluszcz_min = 74;
					tluszcz_max = 130;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 2200;
					tluszcz_min = 50;
					tluszcz_max = 85;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2550;
					tluszcz_min = 57;
					tluszcz_max = 99;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2900;
					tluszcz_min = 64;
					tluszcz_max = 113;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 3290;
					tluszcz_min = 73;
					tluszcz_max = 127.6;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3650;
					tluszcz_min = 81;
					tluszcz_max = 142;
				}
			}
			if (some.GetWeight() >= 80 && some.GetWeight() < 90)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 2350;
					tluszcz_min = 52;
					tluszcz_max = 91;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2750;
					tluszcz_min = 61;
					tluszcz_max = 107;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 3150;
					tluszcz_min = 70;
					tluszcz_max = 123;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 3550;
					tluszcz_min = 79.2;
					tluszcz_max = 138;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3950;
					tluszcz_min = 88;
					tluszcz_max = 154;
				}
			}
		}

		if (some.GetPlec() == 'K')
		{
			if (some.GetWeight() < 50)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1350;
					tluszcz_min = 31;
					tluszcz_max = 52;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1600;
					tluszcz_min = 36;
					tluszcz_max = 62;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1850;
					tluszcz_min = 41;
					tluszcz_max = 72;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2060;
					tluszcz_min = 45.4;
					tluszcz_max = 80.2;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2300;
					tluszcz_min = 51;
					tluszcz_max = 89;
				}
			}
			if (some.GetWeight() >= 50 && some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1500;
					tluszcz_min = 33;
					tluszcz_max = 58;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1800;
					tluszcz_min = 40;
					tluszcz_max = 70;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2100;
					tluszcz_min = 47;
					tluszcz_max = 82;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2360;
					tluszcz_min = 52.4;
					tluszcz_max = 91.4;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2600;
					tluszcz_min = 58;
					tluszcz_max = 101;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1800;
					tluszcz_min = 41;
					tluszcz_max = 71;
				
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2050;
					tluszcz_min = 46;
					tluszcz_max = 80;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2300;
					tluszcz_min = 51;
					tluszcz_max = 89;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2620;
					tluszcz_min = 58.4;
					tluszcz_max = 101.8;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2900;
					tluszcz_min = 64;
					tluszcz_max = 113;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1950;
					tluszcz_min = 43;
					tluszcz_max = 77;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2250;
					tluszcz_min = 50;
					tluszcz_max = 88;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2550;
					tluszcz_min = 57;
					tluszcz_max = 99;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2880;
					tluszcz_min = 63.8;
					tluszcz_max = 112;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3200;
					tluszcz_min = 71;
					tluszcz_max = 124;
				}
			}
		}
	}
	else if (some.GetAge() >= 31 && some.GetAge() <= 50)
	{
		blonnik = 25;
		if (some.GetPlec() == 'M')
		{

			if (some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1800;
					tluszcz_min = 41;
					tluszcz_max = 71;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2100;
					tluszcz_min = 47;
					tluszcz_max = 82;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2400;
					tluszcz_min = 53;
					tluszcz_max = 93;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2680;
					tluszcz_min = 59.8;
					tluszcz_max = 104.2;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3000;
					tluszcz_min = 67;
					tluszcz_max = 117;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1900;
					tluszcz_min = 42;
					tluszcz_max = 75;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2250;
					tluszcz_min = 50;
					tluszcz_max = 88;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2600;
					tluszcz_min = 58;
					tluszcz_max = 101;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2930;
					tluszcz_min = 64.8;
					tluszcz_max = 114;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3250;
					tluszcz_min = 72;
					tluszcz_max = 126;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 2050;
					tluszcz_min = 45;
					tluszcz_max = 79;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2400;
					tluszcz_min = 53;
					tluszcz_max = 93;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2750;
					tluszcz_min = 61;
					tluszcz_max = 107;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 3090;
					tluszcz_min = 69;
					tluszcz_max = 120.4;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3450;
					tluszcz_min = 77;
					tluszcz_max = 134;
				}
			}
			if (some.GetWeight() >= 80 && some.GetWeight() < 90)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 2250;
					tluszcz_min = 50;
					tluszcz_max = 87;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2600;
					tluszcz_min = 58;
					tluszcz_max = 101;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2950;
					tluszcz_min = 66;
					tluszcz_max = 115;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 3340;
					tluszcz_min = 74;
					tluszcz_max = 129.6;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3700;
					tluszcz_min = 82;
					tluszcz_max = 144;
				}
			}
		}

		if (some.GetPlec() == 'K')
		{
			if (some.GetWeight() < 50)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1450;
					tluszcz_min = 33;
					tluszcz_max = 56;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1700;
					tluszcz_min = 38;
					tluszcz_max = 66;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1950;
					tluszcz_min = 43;
					tluszcz_max = 76;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2160;
					tluszcz_min = 48.2;
					tluszcz_max = 84.2;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2400;
					tluszcz_min = 53;
					tluszcz_max = 93;
				}
			}
			if (some.GetWeight() >= 50 && some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1550;
					tluszcz_min = 34;
					tluszcz_max = 60;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1800;
					tluszcz_min = 40;
					tluszcz_max = 70;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2050;
					tluszcz_min = 46;
					tluszcz_max = 80;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2320;
					tluszcz_min = 51.6;
					tluszcz_max = 90.6;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2600;
					tluszcz_min = 58;
					tluszcz_max = 101;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1600;
					tluszcz_min = 35;
					tluszcz_max = 62;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1900;
					tluszcz_min = 42;
					tluszcz_max = 74;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2200;
					tluszcz_min = 49;
					tluszcz_max = 86;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2470;
					tluszcz_min = 54.6;
					tluszcz_max = 95.8;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2750;
					tluszcz_min = 61;
					tluszcz_max = 107;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1750;
					tluszcz_min = 40;
					tluszcz_max = 69;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2050;
					tluszcz_min = 46;
					tluszcz_max = 80;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2350;
					tluszcz_min = 52;
					tluszcz_max = 91;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2620;
					tluszcz_min = 58.4;
					tluszcz_max = 101.8;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2900;
					tluszcz_min = 64;
					tluszcz_max = 113;
				}
			}
		}
	}
	else if (some.GetAge() >= 51 && some.GetAge() <= 65)
	{
		blonnik = 25;
		if (some.GetPlec() == 'M')
		{

			if (some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1700;
					tluszcz_min = 37;
					tluszcz_max = 66;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1950;
					tluszcz_min = 43;
					tluszcz_max = 76;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2200;
					tluszcz_min = 49;
					tluszcz_max = 86;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2520;
					tluszcz_min = 55.6;
					tluszcz_max = 97.8;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2800;
					tluszcz_min = 62;
					tluszcz_max = 109;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1800;
					tluszcz_min = 41;
					tluszcz_max = 71;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2100;
					tluszcz_min = 47;
					tluszcz_max = 82;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2400;
					tluszcz_min = 53;
					tluszcz_max = 93;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2720;
					tluszcz_min = 60.6;
					tluszcz_max = 105.8;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3000;
					tluszcz_min = 67;
					tluszcz_max = 117;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 2000;
					tluszcz_min = 44;
					tluszcz_max = 77;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2300;
					tluszcz_min = 51;
					tluszcz_max = 89;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2600;
					tluszcz_min = 58;
					tluszcz_max = 101;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2930;
					tluszcz_min = 64.8;
					tluszcz_max = 114;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3250;
					tluszcz_min = 72;
					tluszcz_max = 126;
				}
			}
			if (some.GetWeight() >= 80 && some.GetWeight() < 90)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 2100;
					tluszcz_min = 46;
					tluszcz_max = 81;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2450;
					tluszcz_min = 54;
					tluszcz_max = 95;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2800;
					tluszcz_min = 62;
					tluszcz_max = 109;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 3140;
					tluszcz_min = 70;
					tluszcz_max = 122.4;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3500;
					tluszcz_min = 78;
					tluszcz_max = 136;
				}
			}
		}

		if (some.GetPlec() == 'K')
		{
			if (some.GetWeight() < 50)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1370;
					tluszcz_min = 36;
					tluszcz_max = 63;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1610;
					tluszcz_min = 41;
					tluszcz_max = 72;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1850;
					tluszcz_min = 44;
					tluszcz_max = 78;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2060;
					tluszcz_min = 51;
					tluszcz_max = 89;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2300;
					tluszcz_min = 57;
					tluszcz_max = 99;
				}
			}
			if (some.GetWeight() >= 50 && some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1500;
					tluszcz_min = 39;
					tluszcz_max = 68;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1750;
					tluszcz_min = 44;
					tluszcz_max = 78;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2000;
					tluszcz_min = 49;
					tluszcz_max = 86;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2260;
					tluszcz_min = 56;
					tluszcz_max = 97;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2500;
					tluszcz_min = 61;
					tluszcz_max = 107;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1500;
					tluszcz_min = 40;
					tluszcz_max = 70;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1800;
					tluszcz_min = 47;
					tluszcz_max = 82;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2100;
					tluszcz_min = 51;
					tluszcz_max = 89;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2360;
					tluszcz_min = 58;
					tluszcz_max = 101;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2600;
					tluszcz_min = 63;
					tluszcz_max = 111;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1650;
					tluszcz_min = 43;
					tluszcz_max = 76;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1950;
					tluszcz_min = 50;
					tluszcz_max = 88;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2250;
					tluszcz_min = 54;
					tluszcz_max = 95;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2520;
					tluszcz_min = 62;
					tluszcz_max = 109;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2800;
					tluszcz_min = 69;
					tluszcz_max = 121;
				}
			}
		}
	}
	else if (some.GetAge() >= 66 && some.GetAge() <= 75)
	{
		blonnik = 20;
		if (some.GetPlec() == 'M')
		{

			if (some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1450;
					tluszcz_min = 38;
					tluszcz_max = 66;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1700;
					tluszcz_min = 43;
					tluszcz_max = 76;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1950;
					tluszcz_min = 48;
					tluszcz_max = 84;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2210;
					tluszcz_min = 54;
					tluszcz_max = 95;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2450;
					tluszcz_min = 60;
					tluszcz_max = 105;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1650;
					tluszcz_min = 42;
					tluszcz_max = 74;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1900;
					tluszcz_min = 48;
					tluszcz_max = 84;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2150;
					tluszcz_min = 52;
					tluszcz_max = 91;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2420;
					tluszcz_min = 60;
					tluszcz_max = 105;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2700;
					tluszcz_min = 66;
					tluszcz_max = 115;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1750;
					tluszcz_min = 46;
					tluszcz_max = 80;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2050;
					tluszcz_min = 52;
					tluszcz_max = 91;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2350;
					tluszcz_min = 57;
					tluszcz_max = 99;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2630;
					tluszcz_min = 66;
					tluszcz_max = 115;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2950;
					tluszcz_min = 72;
					tluszcz_max = 126;
				}
			}
			if (some.GetWeight() >= 80 && some.GetWeight() < 90)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1900;
					tluszcz_min = 49;
					tluszcz_max = 86;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2200;
					tluszcz_min = 56;
					tluszcz_max = 97;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2500;
					tluszcz_min = 61;
					tluszcz_max = 107;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2830;
					tluszcz_min = 70;
					tluszcz_max = 123;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3150;
					tluszcz_min = 78;
					tluszcz_max = 136;
				}
			}
		}

		if (some.GetPlec() == 'K')
		{
			if (some.GetWeight() < 50)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1300;
					tluszcz_min = 28;
					tluszcz_max = 50;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1500;
					tluszcz_min = 33;
					tluszcz_max = 58;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1700;
					tluszcz_min = 38;
					tluszcz_max = 66;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 1910;
					tluszcz_min = 42.4;
					tluszcz_max = 74.4;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2150;
					tluszcz_min = 48;
					tluszcz_max = 84;
				}
			}
			if (some.GetWeight() >= 50 && some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1350;
					tluszcz_min = 31;
					tluszcz_max = 52;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1600;
					tluszcz_min = 36;
					tluszcz_max = 62;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1850;
					tluszcz_min = 41;
					tluszcz_max = 72;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2100;
					tluszcz_min = 47;
					tluszcz_max = 81.8;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2300;
					tluszcz_min = 51;
					tluszcz_max = 89;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1500;
					tluszcz_min = 34;
					tluszcz_max = 58;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1750;
					tluszcz_min = 39;
					tluszcz_max = 68;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2000;
					tluszcz_min = 44;
					tluszcz_max = 78;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2260;
					tluszcz_min = 50.4;
					tluszcz_max = 88.2;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2500;
					tluszcz_min = 56;
					tluszcz_max = 97;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1650;
					tluszcz_min = 36;
					tluszcz_max = 64;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1900;
					tluszcz_min = 42;
					tluszcz_max = 74;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2150;
					tluszcz_min = 48;
					tluszcz_max = 84;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2420;
					tluszcz_min = 53.6;
					tluszcz_max = 94;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2700;
					tluszcz_min = 60;
					tluszcz_max = 106;
				}
			}
		}
	}
	else // (some.GetAge() > 75)
	{
		blonnik = 20;
		if (some.GetPlec() == 'M')
		{

			if (some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1350;
					tluszcz_min = 36;
					tluszcz_max = 62;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1600;
					tluszcz_min = 41;
					tluszcz_max = 72;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1850;
					tluszcz_min = 46;
					tluszcz_max = 80;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2100;
					tluszcz_min = 51;
					tluszcz_max = 89;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2300;
					tluszcz_min = 57;
					tluszcz_max = 99;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1550;
					tluszcz_min = 40;
					tluszcz_max = 70;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1800;
					tluszcz_min = 46;
					tluszcz_max = 80;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2050;
					tluszcz_min = 50;
					tluszcz_max = 88;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2320;
					tluszcz_min = 58;
					tluszcz_max = 101;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2600;
					tluszcz_min = 62;
					tluszcz_max = 109;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1650;
					tluszcz_min = 43;
					tluszcz_max = 76;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1950;
					tluszcz_min = 50;
					tluszcz_max = 88;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2250;
					tluszcz_min = 54;
					tluszcz_max = 95;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2520;
					tluszcz_min = 62;
					tluszcz_max = 109;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2800;
					tluszcz_min = 69;
					tluszcz_max = 121;
				}
			}
			if (some.GetWeight() >= 80 && some.GetWeight() < 90)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1800;
					tluszcz_min = 47;
					tluszcz_max = 82;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 2100;
					tluszcz_min = 53;
					tluszcz_max = 93;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2400;
					tluszcz_min = 59;
					tluszcz_max = 103;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2720;
					tluszcz_min = 67;
					tluszcz_max = 117;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 3000;
					tluszcz_min = 74;
					tluszcz_max = 130;
				}
			}
		}

		if (some.GetPlec() == 'K')
		{
			if (some.GetWeight() < 50)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1300;
					tluszcz_min = 28;
					tluszcz_max = 50;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1450;
					tluszcz_min = 32;
					tluszcz_max = 56;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1600;
					tluszcz_min = 36;
					tluszcz_max = 62;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 1810;
					tluszcz_min = 40.4;
					tluszcz_max = 70.4;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2050;
					tluszcz_min = 46;
					tluszcz_max = 80;
				}
			}
			if (some.GetWeight() >= 50 && some.GetWeight() < 60)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1350;
					tluszcz_min = 29;
					tluszcz_max = 52;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1550;
					tluszcz_min = 34;
					tluszcz_max = 60;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1750;
					tluszcz_min = 39;
					tluszcz_max = 68;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2000;
					tluszcz_min = 44.2;
					tluszcz_max = 78;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2200;
					tluszcz_min = 49;
					tluszcz_max = 86;
				}
			}
			if (some.GetWeight() >= 60 && some.GetWeight() < 70)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1500;
					tluszcz_min = 34;
					tluszcz_max = 58;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1700;
					tluszcz_min = 38;
					tluszcz_max = 66;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 1900;
					tluszcz_min = 42;
					tluszcz_max = 74;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2160;
					tluszcz_min = 48.2;
					tluszcz_max = 84.2;
				}
				if (abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2400;
					tluszcz_min = 53;
					tluszcz_max = 93;
				}
			}
			if (some.GetWeight() >= 70 && some.GetWeight() < 80)
			{
				if (abs(some.GetPAL() - 1.2) < eps)
				{
					energia = 1650;
					tluszcz_min = 36;
					tluszcz_max = 64;
				}
				if (abs(some.GetPAL() - 1.4) < eps)
				{
					energia = 1850; 
					tluszcz_min = 41;
					tluszcz_max = 72;
				}
				if (abs(some.GetPAL() - 1.6) < eps)
				{
					energia = 2050; 
					tluszcz_min = 46;
					tluszcz_max = 80;
				}
				if (abs(some.GetPAL() - 1.8) < eps)
				{
					energia = 2320; 
					tluszcz_min = 51.6;
					tluszcz_max = 90.6;
				}
				else //(abs(some.GetPAL() - 2.0) < eps)
				{
					energia = 2600; 
					tluszcz_min = 58;
					tluszcz_max = 101;
				}
			}
		}
	}
	aktywnosc_fizyczna = 60;
	
}
