#pragma once
#include <iostream>
#include <string>
#include"Norm.h"

class User
{
	/* Klasa przechowująca dane użytkownika, opcję klas zaprzyjaźnionych z klasą Norm */
	friend class Norm;
	static int ilosc_alergi;
	float weight, height, BMI, PAL;
	int age;
	char plec;
	std::string diet;
	std::string imie;
	std::string* alergie;
	bool gluten;
	bool jaja;
	bool soja;
	bool nabial;
	bool orzech;
	Norm norma;
public:
	User();
	User(float weight, float height, float BMI, float PAL, int age, char plec, string imie);
	float GetWeight() { return weight; }
	float getHeight() { return height; }
	float GetBMI() { return BMI; }
	int GetAge() { return age; }
	std::string GetDiet() { return diet; }
	void GetAlergie();
	char GetPlec() { return plec; }
	float GetPAL() { return PAL; }
	void SetPlec(char plec) { this->plec = plec; }
	void SetNorm(Norm* norma) { this->norma = *norma; }
	void SetPAL(float PAL) { this->PAL = PAL; }
	void SetWeight(float weight) { this->weight = weight; }
	void SetHeight(float height) { this->height = height; }
	void SetBMI(float BMI) { this->BMI = BMI; }
	void SetAge(int age) { this->age = age; }
	void SetDiet();
	void SetAlergie(std::string alergia);
	bool GetGluten() { return gluten; }
	bool GetJaja() { return jaja; }
	bool GetSoja() { return soja; }
	bool GetNabial() { return nabial; }
	bool GetOrzech() { return orzech; }
	int GetIleAlergii() { return ilosc_alergi; }
	std::string GetImie() { return imie; }
};
