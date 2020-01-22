#pragma once
#include <string>
class CsillagRombolo
	//Defini�lja a CsillagRombolo oszt�lyt!Az oszt�lynak legyen egy konstans neve.Az Imperial �s az Executor oszt�lyokat ebb�l sz�rmaztassa.
	//Konstansk�nt legyen defini�lva a maxim�lis / minim�lis leg�nys�g �s maxim�lis / minim�lis turb�l�zersz�m.Az oszt�ly jegyezze mennyi az aktu�lis leg�nys�g �s turb�l�zer.
/*	A CsillagRombolo ne legyen p�ld�nyos�that�.
	- Implement�lja a k�vetkez� absztrakt met�dust :
-int tuzero()
- Implement�lja a k�vetkez� seg�dmet�dusokat a CsillagRombolo oszt�lyhoz
- unsigned int getLegenyseg() : visszat�r az aktu�lis leg�nys�g sz�m�val
- std : string getName() : visszat�r a haj� nev�vel
- void addLegenyseg(unsigned int legenyseg) : hozz�ad legenyseg sz�m� leg�nys�get
- void removeLegenyseg(unsigned int legenyseg) : elt�volit legenyseg sz�m� leg�nys�get
- bool checkUzemkepes() : Vagyis : aktualis_legenyseg >= minimalis_legenyseg ?
-unsigned int getMaxLegenyseg() : visszat�r a haj�hoz rendelhet� maxim�lis leg�nys�gsz�mmal
- unsigned int getMinLegenyseg() : visszat�r a haj�hoz rendelhet� minim�lis leg�nys�gsz�mmal*/

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

