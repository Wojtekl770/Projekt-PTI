#pragma once
#include<string>
#include<vector>
using namespace std;

class FunFact
{
private:
	/* Klasa odpowiadająca za wyświetlanie ciekawostek o tarczycy, wczytywanych z pliku tekstowego */
	vector<string> facts;
	vector<string>::iterator current;
public:
	FunFact(const string& FileName);
	bool operator()();
};

