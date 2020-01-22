#pragma once
#include "CsillagRombolo.h"
#include <string>
class Executor :
	public CsillagRombolo
/*	- Executor - oszt�ly : rendelkezik ion �gy�kkal is, ezt jelezze konstans attrib�tumokkal.Konstruktora megadja a nevet, az aktu�lis leg�nys�gsz�mot,
aktu�lis turb�l�zersz�mot �s aktu�lis ion�gy�sz�mot.
	- A konstruktorban �ll�tsa be a minim�lis(1500) �s maxim�lis(2500) turb�l�zersz�mot.
	- A konstruktorban �ll�tsa be a minim�lis(50000) �s maxim�lis(350000) leg�nys�gsz�mot.
	- A konstruktorban �ll�tsa be a minim�lis(200) �s maxim�lis(300) ion�gy� sz�mot.
	- Megfelel� sz�m� leg�nys�g jelenl�te eset�n a T�zer� 150 * turbolezerszam + 1000 * ionagyuszam*/
{
public:
	Executor(std::string n,unsigned int legenyseg, unsigned int lezer, unsigned int ion):CsillagRombolo(1500,2500,50000,350000,n,legenyseg,lezer),minion(200),maxion(300),aktion(ion)
	{}
	int tuzero() override;
private:
	const unsigned int minion;
	const unsigned int maxion;
	unsigned int aktion;

};

