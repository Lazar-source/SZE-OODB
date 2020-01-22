#pragma once
#include "CsillagRombolo.h"
#include <string>
class Imperial :
	public CsillagRombolo
{
public:
	/*Imperial - osztály : Konstruktora megadja a nevet, aktuális legénységszámot és aktuális turbólézerszámot.
		- Konstruktorban állítsa be a minimális(29000) és maximális(45000) legénységszámot.
		- A konstruktorban állítsa be a minimális(40) és maximális(80) turbólézerszámot.
		- Megfelelõ számú legénység jelenléte esetén : Tûzerõ 100 * turbolezerszam*/
	Imperial(std::string n,unsigned int legenyseg,unsigned int lezer) :CsillagRombolo(40, 80, 29000, 45000, n,legenyseg,lezer)
	{
	}
	~Imperial()
	{

	}
	int tuzero() override;
};

