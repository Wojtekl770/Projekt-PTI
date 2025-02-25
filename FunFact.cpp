#include "FunFact.h"
#include<iostream>
#include<fstream>
#include<algorithm>

FunFact::FunFact(const string& FileName)
{
	ifstream f(FileName);
	string line;
	if (!f) {
		cout << "Brak pliku ?" << endl;
		return;
	}
	while(getline(f, line)) {
		if(!line.empty()) facts.push_back(line);
	}
	f.close();
	random_shuffle(facts.begin(), facts.end()); 
	current = facts.begin();
}
bool FunFact::operator()() {
	if (current == facts.end()) {
		cout << "Obejrzales ju¿ wszystkie ciekawostki" << endl;
		cout << "Teraz beda sie wyswietlaly te same, w losowej kolejnosci" << endl;
		return 1;
	}
	cout << *current++ << endl << endl;
	return 0;
}