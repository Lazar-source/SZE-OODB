#pragma once
#include "CsillagRombolo.h"
#include <string>
class Executor :
	public CsillagRombolo
/*	- Executor - osztály : rendelkezik ion ágyúkkal is, ezt jelezze konstans attribútumokkal.Konstruktora megadja a nevet, az aktuális legénységszámot,
aktuális turbólézerszámot és aktuális ionágyúszámot.
	- A konstruktorban állítsa be a minimális(1500) és maximális(2500) turbólézerszámot.
	- A konstruktorban állítsa be a minimális(50000) és maximális(350000) legénységszámot.
	- A konstruktorban állítsa be a minimális(200) és maximális(300) ionágyú számot.
	- Megfelelõ számú legénység jelenléte esetén a Tûzerõ 150 * turbolezerszam + 1000 * ionagyuszam*/
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

