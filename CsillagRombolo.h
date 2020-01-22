#pragma once
#include <string>
class CsillagRombolo
	//Definiálja a CsillagRombolo osztályt!Az osztálynak legyen egy konstans neve.Az Imperial és az Executor osztályokat ebbõl származtassa.
	//Konstansként legyen definiálva a maximális / minimális legénység és maximális / minimális turbólézerszám.Az osztály jegyezze mennyi az aktuális legénység és turbólézer.
/*	A CsillagRombolo ne legyen példányosítható.
	- Implementálja a következõ absztrakt metódust :
-int tuzero()
- Implementálja a következõ segédmetódusokat a CsillagRombolo osztályhoz
- unsigned int getLegenyseg() : visszatér az aktuális legénység számával
- std : string getName() : visszatér a hajó nevével
- void addLegenyseg(unsigned int legenyseg) : hozzáad legenyseg számú legénységet
- void removeLegenyseg(unsigned int legenyseg) : eltávolit legenyseg számú legénységet
- bool checkUzemkepes() : Vagyis : aktualis_legenyseg >= minimalis_legenyseg ?
-unsigned int getMaxLegenyseg() : visszatér a hajóhoz rendelhetõ maximális legénységszámmal
- unsigned int getMinLegenyseg() : visszatér a hajóhoz rendelhetõ minimális legénységszámmal*/

{
public:
	CsillagRombolo(unsigned int mint, unsigned int maxt, unsigned int minl, unsigned int maxl, std::string n,unsigned int legenyseg, unsigned int lezer) : minlegeny(minl), maxlegeny(maxl), minturbo(mint), maxturbo(maxt), name(n), akt_legenyseg(legenyseg), akt_turbolezer(lezer)
	{}
	~CsillagRombolo();
	virtual int tuzero() = 0;
	unsigned int getLegenyseg();
	std::string getName();
	void addLegenyseg(unsigned int legenyseg);
	void removeLegenyseg(unsigned int legenyseg);
	bool checkUzemkepes();
	unsigned int getMaxLegenyseg();
	unsigned int getMinLegenyseg();
protected:
	const std::string name;
	const unsigned int minlegeny;
	const unsigned int maxlegeny;
	const unsigned int minturbo;
	const unsigned int maxturbo;
	unsigned int akt_legenyseg;
	unsigned int akt_turbolezer;

	
	
};

