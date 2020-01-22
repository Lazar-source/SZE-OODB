#pragma once
#include <vector>
#include <string>

#include "CsillagRombolo.h"
#include "ErrorLegenyseg.h"
#include "ErrorTartalekos.h"
class Flotta
{
	/*-Készítsen egy flotta osztályt, ami tartalmaz csillagrombolókat!A Flotta csak egyszer példányosulhat, legyen ez az osztály singleton(ld.Singleton design pattern).
		A flotta tartsa számon a tartalék legénységet is, ami kezdetben 0.
		- Konstruktora nem hívható meg kívülrõl.Copy konstruktor és assignment legyen letiltva.
		- A getInstance() nevû statikus metóduson keresztül érhetõ el az egyetlen példányra mutató pointer.A freeInstance szabadítsa fel az egyetlen példányt
		- Az addCsillagrombolo metódussal lehet új csillagrombolót hozzáadni, egy CsillagRombolo mutatót várva argumentumként.
		- A flottából lekérdezhetõ egy csillagromboló a nevével(getCsillagrombolo).Ekkor térjen vissza az adott csillagrombolóra mutató pointerrel.
		- A flotta adja vissza, hogy aktuálisan hány darab csillagromboló van a flottában. (getQuantity)
		-A flottához lehessen hozzárendelni tartalék legénységet, aminek bemenõ paramétere egy pozitív egész szám(rendelTartalekLegenyseg).
		Lehessen lekérdezni az aktuális tartaléklegénységet!*/
public:
	static Flotta* getInstance()
	{
		static Flotta * instance = new Flotta();
		return  instance;
	}
	static  Flotta* freeInstance()
	{
		delete getInstance();
		return nullptr;

	}
	Flotta(Flotta const&) = delete;
	void operator=(Flotta const&) = delete;
	void addCsillagrombolo(CsillagRombolo * rombolo);
	CsillagRombolo* getCsillagRombolo(std::string n);
	unsigned int getQuantity();
	void rendelTartalekLegenyseg(unsigned int legenyseg);
	unsigned int getTartalekLegenyseg();
	void  addLegenyseg(std::string n, unsigned int db);
	void  addLegenyseg(CsillagRombolo *rombolo, unsigned int db);
	void  tartalekbaHelyez(std::string n, unsigned int db);
	unsigned int getOsszesLegenyseg();
	CsillagRombolo* checkImmobility();
	void addLegenysegChecked(CsillagRombolo * rombolo, unsigned int db);
	void tartalekbaHelyezChecked(CsillagRombolo *rombolo, unsigned int db);
	void removeTartalekosChecked(unsigned int db);
private:
	unsigned int tartalek_legenyseg;
	Flotta()
	{
		tartalek_legenyseg = 0;
	}
	std::vector<CsillagRombolo*> g1;
};

