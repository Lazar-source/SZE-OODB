#pragma once
#include <vector>
#include <string>

#include "CsillagRombolo.h"
#include "ErrorLegenyseg.h"
#include "ErrorTartalekos.h"
class Flotta
{
	/*-K�sz�tsen egy flotta oszt�lyt, ami tartalmaz csillagrombol�kat!A Flotta csak egyszer p�ld�nyosulhat, legyen ez az oszt�ly singleton(ld.Singleton design pattern).
		A flotta tartsa sz�mon a tartal�k leg�nys�get is, ami kezdetben 0.
		- Konstruktora nem h�vhat� meg k�v�lr�l.Copy konstruktor �s assignment legyen letiltva.
		- A getInstance() nev� statikus met�duson kereszt�l �rhet� el az egyetlen p�ld�nyra mutat� pointer.A freeInstance szabad�tsa fel az egyetlen p�ld�nyt
		- Az addCsillagrombolo met�dussal lehet �j csillagrombol�t hozz�adni, egy CsillagRombolo mutat�t v�rva argumentumk�nt.
		- A flott�b�l lek�rdezhet� egy csillagrombol� a nev�vel(getCsillagrombolo).Ekkor t�rjen vissza az adott csillagrombol�ra mutat� pointerrel.
		- A flotta adja vissza, hogy aktu�lisan h�ny darab csillagrombol� van a flott�ban. (getQuantity)
		-A flott�hoz lehessen hozz�rendelni tartal�k leg�nys�get, aminek bemen� param�tere egy pozit�v eg�sz sz�m(rendelTartalekLegenyseg).
		Lehessen lek�rdezni az aktu�lis tartal�kleg�nys�get!*/
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

