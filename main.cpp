#include<iostream>
#include<fstream>
#include<ctime>
#include<Windows.h>
#include<vector>
#include<iomanip>
#include"User.h"
#include"Norm.h"
#include"Food.h"
#include<algorithm>
#include"FunFact.h"
#include"Exercise.h"

using namespace std;

const string FFfile = "FunFacts.txt"; // Nazwa pliku z ciekawostkami

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
void setGreen() { SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY); }
void setDefault() { SetConsoleTextAttribute(hOut, 0x0007); }
void TitleSetUp();
void menu(User some, fstream& filename, vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady, vector<Base>& eaten);
void LoadFood(vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady);
template <typename T>
void Check(T& value);
void AddFood(vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady);
void WhatDidIEatToday(vector<Base>& eaten);
void GenerateMeal(vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady, User some, vector<Base>& eaten);
void FoodToFile(vector<Base>& eaten, vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady); //Wpisywanie posilkow do pliku (jeszcze nie gotowe)

int main()
 {
	
	vector<Base> eaten;
	vector<Owoce> owoce;
	vector<Food> napoje, lunche, desery, obiady;
	LoadFood(owoce, napoje, lunche, desery, obiady);
	
	TitleSetUp();
	string check;
	cout << "Czy korzystales/as juz z aplikacji?(tak/nie) " << endl;
	cin >> check;
	if (check == "tak")
	{
		string file_name;
		cout << "Podaj swoje imie: " << endl;
		cin >> file_name;
		file_name.append(".txt");
		fstream MyFile(file_name);
		string imie;
		int age;
		float height, weight, BMI, PAL;
		char plec;
		bool gluten, jaja, soja, nabial, orzech;
		MyFile >> imie >> age >> BMI >> height >> weight >> plec >> PAL>>gluten>>jaja>>soja>>nabial>>orzech;
		User A(weight, height, BMI, PAL, age, plec, imie,gluten,jaja,soja,nabial,orzech);
		menu(A, MyFile, owoce, napoje, lunche, desery, obiady, eaten);
	}
	else
	{
		cout << endl << endl << "Wpisz prosze swoje dane, dzieki czemu aplikacja bedzie mogla byc dopasowana do twoich potrzeb." << endl << endl;
		User A;
		std::string file_name = A.GetImie().append(".txt");
		fstream MyFile;
		MyFile.open(file_name, fstream::out);
		MyFile << A.GetImie() << endl;
		MyFile << A.GetAge() << endl;
		MyFile << A.GetBMI() << endl;
		MyFile << A.getHeight() << endl;
		MyFile << A.GetWeight() << endl;
		MyFile << A.GetPlec() << endl;
		MyFile << A.GetPAL() << endl;
		MyFile << A.GetGluten() << endl;
		MyFile << A.GetJaja() << endl;
		MyFile << A.GetSoja() << endl;
		MyFile << A.GetNabial() << endl;
		MyFile << A.GetOrzech() << endl;
		menu(A, MyFile, owoce, napoje, lunche, desery, obiady, eaten);
	}
	return 0;
	
}


void TitleSetUp()
{
	/*
	Funkcja czysci zawartosc konsoli i drukuje ekran tytulowy (niebieskie gwiazdki i motto),
	nastepnie ustawia kolor z powrotem na bialy
	*/
	system("cls");
	HANDLE  hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string motto = " Zdrowe zywienie to podstawa ";

	for (int i = 0; i < 120; i++)
	{
		if (i >= 46 && i < 75)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << motto.at(i - 46);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 11);
			cout << '*';
		}
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	string przywitanie = " Witaj w naszej aplikacji! ";

	for (int i = 0; i < 120; i++)
	{
		if (i >= 47 && i < 74)
		{
			cout << przywitanie.at(i - 47);
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 11);
			cout << "*";
		}
	}
	SetConsoleTextAttribute(hConsole, 15);

}
void menu(User some, fstream& filename, vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady, vector<Base>& eaten)
{
	/*
		Wybór opcji przez użytkownika
	*/

	FunFact FunFacts(FFfile);
	HANDLE  hConsole;
	bool running = true;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (running)
	{
		TitleSetUp();
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Witaj " << some.GetImie() << "! Co chcesz dzisiaj zrobic? Wybierz opcje 1. - 6." << endl;
		cout << "1. Edytuj dane o uzytkowniku" << endl << "2. Wpisz nowy posilek" << endl << "3. Sprawdz co dzisiaj jadles/as" << endl<<"4. Sprawdz swoje normy spozycia" << endl << "5. Wpisz nowe cwiczenie" << endl << "6. Pokaz ciekawostke" <<endl<<"7. Wpisz nowy posilek do bazy danych" << endl << "8. Wylosuj posilek"<<endl<< "9. Wyjdz z aplikacji" << endl;
		int opcja;
		cin >> opcja;
		TitleSetUp();
		Exercise ex;
		switch (opcja)
		{
			case 1: some = User(); break;
			case 2: FoodToFile(eaten, owoce, napoje, lunche, desery, obiady); break;
			case 3: WhatDidIEatToday(eaten); break;
			case 4: cout << Norm(some); break;
			case 5: ex.NewEx(); break;
			case 6: if (FunFacts()) FunFacts = FunFact(FFfile); break;
			case 7: AddFood(owoce, napoje, lunche, desery, obiady);; break;
			case 8: GenerateMeal(owoce, napoje, lunche, desery, obiady, some,eaten); break;
			case 9: {
				filename.close();
				running = false;
			} break;
		}
		if (running) system("pause");
	}
}
void FoodToFile(vector<Base>& eaten, vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady)
{
	/* Zapis zjedzonego posiłku do wektora eaten */
	cout << "Wybierz od 1 do 5 co chcesz dodac " << endl;
	int wybor = 0;
	
	cout << "------------------------------------" << endl;
	cout << "1) Deseru" << setw(25) << "2) Duzy posilek" << endl;
	cout << "3) Napoj" << setw(28) << "4) Owoc / Warzywo" << endl;
	cout << "5) Lunch" << endl;
	cout << "------------------------------------" << endl;
	cout << "Wybierz opcje: ";

	while (!(cin >> wybor) && (wybor > 5 || wybor < 1)) {
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Podaj poprawna wartosc: ";
	}
	
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	
	switch (wybor)
	{
	case 1:
		for_each(desery.begin(), desery.end(), [](const Food Mniam) {cout << Mniam; });
		break;
	case 2:
		for_each(obiady.begin(), obiady.end(), [](const Food Mniam) {cout << Mniam; });
		break;
	case 3:
		for_each(napoje.begin(), napoje.end(), [](const Food Mniam) {cout << Mniam; });
		break;
	case 4:
		for_each(owoce.begin(), owoce.end(), [](const Owoce Mniam) {cout << Mniam; });
		break;
	case 5:
		for_each(lunche.begin(), lunche.end(), [](const Food Mniam) {cout << Mniam; });
		break;
	default:
		break;
	}
	cout << "Podaj index produktu który zjadles: " << endl;
	int id;
	bool IsCorrect = false;
	cin >> id;
	switch (wybor)
	{
	case 1:
		for_each(desery.begin(), desery.end(), [id, &eaten, &IsCorrect](const Food Mniam) {if (Mniam.getindex() == id) {
			eaten.push_back(Mniam);
			IsCorrect = true;
		}});
		break;
	case 2:
		for_each(obiady.begin(), obiady.end(), [id, &eaten, &IsCorrect](const Food Mniam) {if (Mniam.getindex() == id) {
			eaten.push_back(Mniam);
			IsCorrect = true;
		}});
		break;
	case 3:
		for_each(napoje.begin(), napoje.end(), [id, &eaten, &IsCorrect](const Food Mniam) {if (Mniam.getindex() == id) {
			eaten.push_back(Mniam);
			IsCorrect = true;
		}});
		break;
	case 4:
		for_each(owoce.begin(), owoce.end(), [id, &eaten, &IsCorrect](const Owoce Mniam) {if (Mniam.getindex() == id) {
			eaten.push_back(Mniam);
			IsCorrect = true;
		}});
		break;
	case 5:
		for_each(lunche.begin(), lunche.end(), [id, &eaten, &IsCorrect](const Food Mniam) {if (Mniam.getindex() == id) {
			eaten.push_back(Mniam);
			IsCorrect = true;
		}});
		break;

	default:
		break;
	}
	if (!IsCorrect) cout << "Niepoprawny index";

}


void LoadFood(vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady) 
{
	/* Wczytywanie danych o produktach z plików tekstowych */
	fstream plik;
	plik.open("OWOCE.txt");

	string nazwa;
	int kcal;
	int index = 1;
	double tluszcz;
	double cholesterol;
	double weglowodany;
	double blonnik;
	double bialko;
	double magnez;
	double zelazo;
	double wapn;

	double cukry;
	double sol;

	bool alergia_gluten;
	bool alergia_jaja;
	bool alergia_soja;
	bool alergia_nabial;
	bool alergia_orzech;

	bool czy_ma_mieso;

	while (plik.good()) {
		getline(plik, nazwa);
		plik >> kcal;
		plik >> tluszcz;
		plik >> cholesterol;
		plik >> weglowodany;
		plik >> blonnik;
		plik >> bialko;
		plik >> magnez;
		plik >> zelazo;
		plik >> wapn;
		plik.ignore();
		owoce.push_back(Owoce(nazwa, kcal, tluszcz, cholesterol, weglowodany, blonnik, bialko, index, magnez, zelazo, wapn));
		index++;
	}
	plik.close();
	index = 1;

	plik.open("DESERY.txt");
	while (plik.good()) {
		getline(plik, nazwa);
		plik >> kcal;
		plik >> tluszcz;
		plik >> weglowodany;
		plik >> cukry;
		plik >> blonnik;
		plik >> bialko;
		plik >> sol;
		plik >> alergia_gluten;
		plik >> alergia_jaja;
		plik >> alergia_soja;
		plik >> alergia_nabial;
		plik >> alergia_orzech;
		plik >> czy_ma_mieso;
		plik.ignore();
		desery.push_back(Food(nazwa, kcal, tluszcz, weglowodany, cukry, blonnik, bialko, index, sol, alergia_gluten, alergia_jaja, alergia_soja, alergia_nabial, alergia_orzech, czy_ma_mieso));
		index++;
	}
	plik.close();
	index = 1;

	plik.open("LUNCHE.txt");
	while (plik.good()) {
		getline(plik, nazwa);
		plik >> kcal;
		plik >> tluszcz;
		plik >> weglowodany;
		plik >> cukry;
		plik >> blonnik;
		plik >> bialko;
		plik >> sol;
		plik >> alergia_gluten;
		plik >> alergia_jaja;
		plik >> alergia_soja;
		plik >> alergia_nabial;
		plik >> alergia_orzech;
		plik >> czy_ma_mieso;
		plik.ignore();
		lunche.push_back(Food(nazwa, kcal, tluszcz, weglowodany, cukry, blonnik, bialko, index, sol, alergia_gluten, alergia_jaja, alergia_soja, alergia_nabial, alergia_orzech, czy_ma_mieso));
		index++;
	}

	plik.close();
	index = 1;

	plik.open("OBIADY.txt");

	while (plik.good()) {
		getline(plik, nazwa);
		plik >> kcal;
		plik >> tluszcz;
		plik >> weglowodany;
		plik >> cukry;
		plik >> blonnik;
		plik >> bialko;
		plik >> sol;
		plik >> alergia_gluten;
		plik >> alergia_jaja;
		plik >> alergia_soja;
		plik >> alergia_nabial;
		plik >> alergia_orzech;
		plik >> czy_ma_mieso;
		plik.ignore();
		obiady.push_back(Food(nazwa, kcal, tluszcz, weglowodany, cukry, blonnik, bialko, index, sol, alergia_gluten, alergia_jaja, alergia_soja, alergia_nabial, alergia_orzech, czy_ma_mieso));
		index++;
	}
	plik.close();
	index = 1;
	plik.open("NAPOJE.txt");

	while (plik.good()) {
		getline(plik, nazwa);
		plik >> kcal;
		plik >> tluszcz;
		plik >> weglowodany;
		plik >> cukry;
		plik >> blonnik;
		plik >> bialko;
		plik >> sol;
		plik >> alergia_gluten;
		plik >> alergia_jaja;
		plik >> alergia_soja;
		plik >> alergia_nabial;
		plik >> alergia_orzech;
		plik >> czy_ma_mieso;
		plik.ignore();
		napoje.push_back(Food(nazwa, kcal, tluszcz, weglowodany, cukry, blonnik, bialko, index, sol, alergia_gluten, alergia_jaja, alergia_soja, alergia_nabial, alergia_orzech, czy_ma_mieso));
		index++;
	}
	plik.close();
	cout << endl;
}

template <typename T>
void Check(T& value) {
	while (!(cin >> value)) {
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Podaj poprawna wartosc: ";
	}
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
}

void AddFood(vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady) 
{
 	/* Funkcja umożliwiająca wpisywanie nowych produktów do bazy danych */	
	string nazwa;
	int kcal;
	int index;
	double tluszcz;
	double cholesterol;
	double weglowodany;
	double blonnik;
	double bialko;
	double magnez;
	double zelazo;
	double wapn;

	double cukry;
	double sol;

	bool alergia_gluten;
	bool alergia_jaja;
	bool alergia_soja;
	bool alergia_nabial;
	bool alergia_orzech;

	bool czy_ma_mieso;


	cout << "Wybierz od 1 do 5 co chcesz dodac " << endl;
	int wybor = 0;
	do {
		cout << "------------------------------------" << endl;
		cout << "1) Deseru" << setw(25) << "2) Duzy posilek" << endl;
		cout << "3) Napoj" << setw(28) << "4) Owoc / Warzywo" << endl;
		cout << "5) Lunch" << endl;
		cout << "------------------------------------" << endl;
		cout << "Wybierz opcje: ";

		while (!(cin >> wybor) && (wybor > 5 || wybor < 1)) {
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Podaj poprawna wartosc: ";
		}

		cout << endl;
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

		ofstream plik;

		switch (wybor) {
		case (1):
			setGreen();
			cout << "Wybrano dodanie deseru" << endl;
			setDefault();
			plik.open("DESERY.txt", ios::app);
			cout << "Podaj nazwe deseru: ";
			getline(cin, nazwa);
			plik << endl << nazwa << endl;
			cout << "Podaj ilosc kcal: ";
			Check(kcal);
			plik << kcal << endl;
			cout << "Podaj ilosc tluszczu w gramach: ";
			Check(tluszcz);
			plik << tluszcz << endl;
			cout << "Podaj ilosc weglowodanyow w gramach: ";
			Check(weglowodany);
			plik << weglowodany << endl;
			cout << "Podaj ilosc cukru w gramach: ";
			Check(cukry);
			plik << cukry << endl;
			cout << "Podaj ilosc blonnika w gramach: ";
			Check(blonnik);
			plik << blonnik << endl;
			cout << "Podaj ilosc bialka w gramach: ";
			Check(bialko);
			plik << bialko << endl;
			cout << "Podaj ilosc soli w gramach: ";
			Check(sol);
			plik << sol << endl;
			cout << "Czy zawiera gluten (1 - Tak, 0 - Nie): ";
			Check(alergia_gluten);
			plik << alergia_gluten << endl;
			cout << "Czy zawiera jajka (1 - Tak, 0 - Nie): ";
			Check(alergia_jaja);
			plik << alergia_jaja << endl;
			cout << "Czy zawiera soje (1 - Tak, 0 - Nie): ";
			Check(alergia_soja);
			plik << alergia_soja << endl;
			cout << "Czy zawiera nabial (1 - Tak, 0 - Nie): ";
			Check(alergia_nabial);
			plik << alergia_nabial << endl;
			cout << "Czy zawiera orzechy (1 - Tak, 0 - Nie): ";
			Check(alergia_orzech);
			plik << alergia_orzech << endl;
			cout << "Czy zawiera mieso (1 - Tak, 0 - Nie): ";
			while (!(cin >> czy_ma_mieso)) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Podaj poprawna wartosc: ";
			}
			plik << czy_ma_mieso;
			index = desery.back().getindex() + 1;
			desery.push_back(Food(nazwa, kcal, tluszcz, weglowodany, cukry, blonnik, bialko, index, sol, alergia_gluten, alergia_jaja, alergia_soja, alergia_nabial, alergia_orzech, czy_ma_mieso));
			plik.close();
			break;

		case (2):
			setGreen();
			cout << "Wybrano dodanie obiadu" << endl;
			setDefault();
			plik.open("OBIADY.txt", ios::app);
			cout << "Podaj nazwe duzego posilku: ";
			getline(cin, nazwa);
			plik << endl << nazwa << endl;
			cout << "Podaj ilosc kcal: ";
			Check(kcal);
			plik << kcal << endl;
			cout << "Podaj ilosc tluszczu w gramach: ";
			Check(tluszcz);
			plik << tluszcz << endl;
			cout << "Podaj ilosc weglowodanyow w gramach: ";
			Check(weglowodany);
			plik << weglowodany << endl;
			cout << "Podaj ilosc cukru w gramach: ";
			Check(cukry);
			plik << cukry << endl;
			cout << "Podaj ilosc blonnika w gramach: ";
			Check(blonnik);
			plik << blonnik << endl;
			cout << "Podaj ilosc bialka w gramach: ";
			Check(bialko);
			plik << bialko << endl;
			cout << "Podaj ilosc soli w gramach: ";
			Check(sol);
			plik << sol << endl;
			cout << "Czy zawiera gluten (1 - Tak, 0 - Nie): ";
			Check(alergia_gluten);
			plik << alergia_gluten << endl;
			cout << "Czy zawiera jajka (1 - Tak, 0 - Nie): ";
			Check(alergia_jaja);
			plik << alergia_jaja << endl;
			cout << "Czy zawiera soje (1 - Tak, 0 - Nie): ";
			Check(alergia_soja);
			plik << alergia_soja << endl;
			cout << "Czy zawiera nabial (1 - Tak, 0 - Nie): ";
			Check(alergia_nabial);
			plik << alergia_nabial << endl;
			cout << "Czy zawiera orzechy (1 - Tak, 0 - Nie): ";
			Check(alergia_orzech);
			plik << alergia_orzech << endl;
			cout << "Czy zawiera mieso (1 - Tak, 0 - Nie): ";
			while (!(cin >> czy_ma_mieso)) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Podaj poprawna wartosc: ";
			}
			plik << czy_ma_mieso;
			index = obiady.back().getindex() + 1;
			obiady.push_back(Food(nazwa, kcal, tluszcz, weglowodany, cukry, blonnik, bialko, index, sol, alergia_gluten, alergia_jaja, alergia_soja, alergia_nabial, alergia_orzech, czy_ma_mieso));
			plik.close();
			break;

		case (3):
			setGreen();
			cout << "Wybrano dodanie napoju" << endl;
			setDefault();
			plik.open("NAPOJE.txt", ios::app);
			cout << "Podaj nazwe napoju: ";
			getline(cin, nazwa);
			plik << endl << nazwa << endl;
			cout << "Podaj ilosc kcal: ";
			Check(kcal);
			plik << kcal << endl;
			cout << "Podaj ilosc tluszczu w gramach: ";
			Check(tluszcz);
			plik << tluszcz << endl;
			cout << "Podaj ilosc weglowodanyow w gramach: ";
			Check(weglowodany);
			plik << weglowodany << endl;
			cout << "Podaj ilosc cukru w gramach: ";
			Check(cukry);
			plik << cukry << endl;
			cout << "Podaj ilosc blonnika w gramach: ";
			Check(blonnik);
			plik << blonnik << endl;
			cout << "Podaj ilosc bialka w gramach: ";
			Check(bialko);
			plik << bialko << endl;
			cout << "Podaj ilosc soli w gramach: ";
			Check(sol);
			plik << sol << endl;
			cout << "Czy zawiera gluten (1 - Tak, 0 - Nie): ";
			Check(alergia_gluten);
			plik << alergia_gluten << endl;
			cout << "Czy zawiera jajka (1 - Tak, 0 - Nie): ";
			Check(alergia_jaja);
			plik << alergia_jaja << endl;
			cout << "Czy zawiera soje (1 - Tak, 0 - Nie): ";
			Check(alergia_soja);
			plik << alergia_soja << endl;
			cout << "Czy zawiera nabial (1 - Tak, 0 - Nie): ";
			Check(alergia_nabial);
			plik << alergia_nabial << endl;
			cout << "Czy zawiera orzechy (1 - Tak, 0 - Nie): ";
			Check(alergia_orzech);
			plik << alergia_orzech << endl;
			cout << "Czy zawiera mieso (1 - Tak, 0 - Nie): ";
			while (!(cin >> czy_ma_mieso)) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Podaj poprawna wartosc: ";
			}
			plik << czy_ma_mieso;
			index = napoje.back().getindex() + 1;
			napoje.push_back(Food(nazwa, kcal, tluszcz, weglowodany, cukry, blonnik, bialko, index, sol, alergia_gluten, alergia_jaja, alergia_soja, alergia_nabial, alergia_orzech, czy_ma_mieso));
			plik.close();
			break;

		case(4):
			setGreen();
			cout << "Wybrano dodanie owocu albo warzywa" << endl;
			setDefault();
			plik.open("OWOCE.txt", ios::app);
			cout << "Podaj nazwe owocu / warzywa: ";
			getline(cin, nazwa);
			plik << endl << nazwa << endl;
			cout << "Podaj ilosc kcal: ";
			Check(kcal);
			plik << kcal << endl;
			cout << "Podaj ilosc tluszczu w gramach: ";
			Check(tluszcz);
			plik << tluszcz << endl;
			cout << "Podaj ilosc cholesterolu w gramach: ";
			Check(cholesterol);
			plik << cholesterol << endl;
			cout << "Podaj ilosc weglowodanyow w gramach: ";
			Check(weglowodany);
			plik << weglowodany << endl;
			cout << "Podaj ilosc blonnika w gramach: ";
			Check(blonnik);
			plik << blonnik << endl;
			cout << "Podaj ilosc bialka w gramach: ";
			Check(bialko);
			plik << bialko << endl;
			cout << "Podaj ilosc magnezu w miligramach: ";
			Check(magnez);
			plik << magnez << endl;
			cout << "Podaj ilosc zelaza w miligramach: ";
			Check(zelazo);
			plik << zelazo << endl;
			cout << "Podaj ilosc wapna w miligramach: ";
			while (!(cin >> wapn)) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Podaj poprawna wartosc: ";
			}
			plik << wapn;
			index = owoce.back().getindex() + 1;
			owoce.push_back(Owoce(nazwa, kcal, tluszcz, cholesterol, weglowodany, blonnik, bialko, index, magnez, zelazo, wapn));
			plik.close();
			break;

		case(5):
			setGreen();
			cout << "Wybrano dodanie lunchu" << endl;
			setDefault();
			plik.open("LUNCHE.txt", ios::app);
			cout << "Podaj nazwe lunchu: ";
			getline(cin, nazwa);
			plik << endl << nazwa << endl;
			cout << "Podaj ilosc kcal: ";
			Check(kcal);
			plik << kcal << endl;
			cout << "Podaj ilosc tluszczu w gramach: ";
			Check(tluszcz);
			plik << tluszcz << endl;
			cout << "Podaj ilosc weglowodanyow w gramach: ";
			Check(weglowodany);
			plik << weglowodany << endl;
			cout << "Podaj ilosc cukru w gramach: ";
			Check(cukry);
			plik << cukry << endl;
			cout << "Podaj ilosc blonnika w gramach: ";
			Check(blonnik);
			plik << blonnik << endl;
			cout << "Podaj ilosc bialka w gramach: ";
			Check(bialko);
			plik << bialko << endl;
			cout << "Podaj ilosc soli w gramach: ";
			Check(sol);
			plik << sol << endl;
			cout << "Czy zawiera gluten (1 - Tak, 0 - Nie): ";
			Check(alergia_gluten);
			plik << alergia_gluten << endl;
			cout << "Czy zawiera jajka (1 - Tak, 0 - Nie): ";
			Check(alergia_jaja);
			plik << alergia_jaja << endl;
			cout << "Czy zawiera soje (1 - Tak, 0 - Nie): ";
			Check(alergia_soja);
			plik << alergia_soja << endl;
			cout << "Czy zawiera nabial (1 - Tak, 0 - Nie): ";
			Check(alergia_nabial);
			plik << alergia_nabial << endl;
			cout << "Czy zawiera orzechy (1 - Tak, 0 - Nie): ";
			Check(alergia_orzech);
			plik << alergia_orzech << endl;
			cout << "Czy zawiera mieso (1 - Tak, 0 - Nie): ";
			while (!(cin >> czy_ma_mieso)) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Podaj poprawna wartosc: ";
			}
			plik << czy_ma_mieso;
			index = lunche.back().getindex() + 1;
			lunche.push_back(Food(nazwa, kcal, tluszcz, weglowodany, cukry, blonnik, bialko, index, sol, alergia_gluten, alergia_jaja, alergia_soja, alergia_nabial, alergia_orzech, czy_ma_mieso));
			plik.close();
			break;

		default:
			break;
		}

		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

		cout << endl << "Czy chcesz dodac kolejny posilek? (T - Tak, N - Nie) ";
		char c;
		cin >> c;
		cout << endl;
		if (c == 'N' || c == 'n')
			break;


		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

	} while (true);
}

void WhatDidIEatToday(vector<Base>& eaten)
{
	/* Opcja sprawdzenia zjedzonych produktów z menu */
	for_each(eaten.begin(), eaten.end(), [](const Base Mniam) {cout << Mniam; });
}
void GenerateMeal(vector<Owoce>& owoce, vector<Food>& napoje, vector<Food>& lunche, vector<Food>& desery, vector<Food>& obiady, User some, vector<Base>& eaten)
{
	/* Funkcja umożliwiająca wylosowanie posiłku (opcja z menu) uwzgledniająca alergie */
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Jakiego posilku szukasz? Wybierz opcje 1.-5." << endl
		<< "1. Lunche" << endl << "2. Obiady" << endl << "3. Desery" << endl << "4. Owoce" << endl << "5. Napoje" << endl;
	int opcja;
	cin >> opcja;
	
	Base meal;

	switch (opcja)
	{
	case 1:
	{
		vector<Food>& to_shuffle = lunche;
		bool not_found = true;
		while (not_found)
		{
			random_shuffle(to_shuffle.begin(), to_shuffle.end());
			if (to_shuffle.begin()->getjaja() >= some.GetJaja()
				&& to_shuffle.begin()->getgluten() >= some.GetGluten()
				&& to_shuffle.begin()->getorzech() >= some.GetOrzech()
				&& to_shuffle.begin()->getnabial() >= some.GetNabial()
				&& to_shuffle.begin()->getsoja() >= some.GetSoja()) {
				not_found = false;
				break;
			}
		}
		SetConsoleTextAttribute(hConsole, 11);
		cout << to_shuffle.begin()->getname() << endl << endl << "Wartosci odzywcze na 100g" << endl << to_shuffle.begin()->getkcal() << " kcal, " << to_shuffle.begin()->getbialko() << " g bialka, "
			<< to_shuffle.begin()->getblonnik() << " g blonnika, " << to_shuffle.begin()->getcukry() << " g cukru, " << to_shuffle.begin()->gettluszcz() << " g tluszczu" << endl;
		meal = *to_shuffle.begin();
	}; break;

	case 2:
	{
		vector<Food>& to_shuffle = obiady;
		bool not_found = true;
		while (not_found)
		{
			random_shuffle(to_shuffle.begin(), to_shuffle.end());
			if (to_shuffle.begin()->getjaja() >= some.GetJaja()
				&& to_shuffle.begin()->getgluten() >= some.GetGluten()
				&& to_shuffle.begin()->getorzech() >= some.GetOrzech()
				&& to_shuffle.begin()->getnabial() >= some.GetNabial()
				&& to_shuffle.begin()->getsoja() >= some.GetSoja()) {
				not_found = false;
				break;
			}
		}
		cout << to_shuffle.begin()->getname() << endl << endl << "Wartosci odzywcze na 100g" << endl << to_shuffle.begin()->getkcal() << " kcal, " << to_shuffle.begin()->getbialko() << " g bialka, "
			<< to_shuffle.begin()->getblonnik() << " g blonnika, " << to_shuffle.begin()->getcukry() << " g cukru, " << to_shuffle.begin()->gettluszcz() << " g tluszczu" << endl;
		meal = *to_shuffle.begin();
	}; break;
	case 3:
	{
		vector<Food>& to_shuffle = desery;
		bool not_found = true;
		while (not_found)
		{
			random_shuffle(to_shuffle.begin(), to_shuffle.end());
			if (to_shuffle.begin()->getjaja() >= some.GetJaja()
				&& to_shuffle.begin()->getgluten() >= some.GetGluten()
				&& to_shuffle.begin()->getorzech() >= some.GetOrzech()
				&& to_shuffle.begin()->getnabial() >= some.GetNabial()
				&& to_shuffle.begin()->getsoja() >= some.GetSoja()) {
				not_found = false;
				break;
			}
		}
		cout << to_shuffle.begin()->getname() << endl << endl << "Wartosci odzywcze na 100g" << endl << to_shuffle.begin()->getkcal() << " kcal, " << to_shuffle.begin()->getbialko() << " g bialka, "
			<< to_shuffle.begin()->getblonnik() << " g blonnika, " << to_shuffle.begin()->getcukry() << " g cukru, " << to_shuffle.begin()->gettluszcz() << " g tluszczu" << endl;
		meal = *to_shuffle.begin();
	}; break;
	case 4:
	{
		vector<Owoce>& to_shuffle = owoce;
		bool not_found = true;
		//while (not_found)
		//{
		random_shuffle(to_shuffle.begin(), to_shuffle.end());
		/*	if (to_shuffle.begin()->getjaja() != some.GetJaja()
				&& to_shuffle.begin()->getgluten() != some.GetGluten()
				&& to_shuffle.begin()->getorzech() != some.GetOrzech()
				&& to_shuffle.begin()->getnabial() != some.GetNabial()
				&& to_shuffle.begin()->getsoja() != some.GetSoja()) break;
		}*/
		cout << to_shuffle.begin()->getname() << endl << endl << "Wartosci odzywcze na 100g" << endl << to_shuffle.begin()->getkcal() << " kcal, " << to_shuffle.begin()->getbialko() << " g bialka, "
			<< to_shuffle.begin()->getblonnik() << " g blonnika, " << to_shuffle.begin()->gettluszcz() << " g tluszczu" << endl;
		meal = *to_shuffle.begin();
	}; break;
	case 5:
	{
		vector<Food>& to_shuffle = napoje;
		bool not_found = true;
		while (not_found)
		{
			random_shuffle(to_shuffle.begin(), to_shuffle.end());
			if (to_shuffle.begin()->getjaja() >= some.GetJaja()
				&& to_shuffle.begin()->getgluten() >= some.GetGluten()
				&& to_shuffle.begin()->getorzech() >= some.GetOrzech()
				&& to_shuffle.begin()->getnabial() >= some.GetNabial()
				&& to_shuffle.begin()->getsoja() >= some.GetSoja()) {
				not_found = false;
				break;
			}
		}
		cout << to_shuffle.begin()->getname() << endl << endl << "Wartosci odzywcze na 100g" << endl << to_shuffle.begin()->getkcal() << " kcal, " << to_shuffle.begin()->getbialko() << " g bialka "
			<< to_shuffle.begin()->getblonnik() << " g blonnika, " << to_shuffle.begin()->getcukry() << " g cukru, " << to_shuffle.begin()->gettluszcz() << " g tluszczu" << endl;
		meal = *to_shuffle.begin();
	}; break;
	}
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Co chcesz zrobic z posilkiem? Wybierz opcje 1-3." << endl << "1. Wpisz posilek" << endl << "2. Losuj kolejny" << endl << "3. Anuluj" << endl;
	int opcja2;
	cin >> opcja2;
	switch (opcja2)
	{
	case 1: {
		eaten.push_back(meal);
		break; 
	}
	case 2: GenerateMeal(owoce, napoje, lunche, desery, obiady, some, eaten); break;
	case 3: break;
	}
}
