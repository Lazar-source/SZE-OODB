#pragma once
#include "CsillagRombolo.h"
#include <string>
class Imperial :
	public CsillagRombolo
{
public:
	/*Imperial - oszt�ly : Konstruktora megadja a nevet, aktu�lis leg�nys�gsz�mot �s aktu�lis turb�l�zersz�mot.
		- Konstruktorban �ll�tsa be a minim�lis(29000) �s maxim�lis(45000) leg�nys�gsz�mot.
		- A konstruktorban �ll�tsa be a minim�lis(40) �s maxim�lis(80) turb�l�zersz�mot.
		- Megfelel� sz�m� leg�nys�g jelenl�te eset�n : T�zer� 100 * turbolezerszam*/
	Imperial(std::string n,unsigned int legenyseg,unsigned int lezer) :CsillagRombolo(40, 80, 29000, 45000, n,legenyseg,lezer)
	{
	}
	~Imperial()
	{

	}
	int tuzero() override;
};

