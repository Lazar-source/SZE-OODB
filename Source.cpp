/*
FIGYELEM! A vizsga megkezd�se el�tt ezt olvassa �t.
-	A k�l�nb�z� szintekhez (2,3,4,5) a #define makr�kat kell �ll�tani 0-r�l 1-re.
-	Ahol kiemeleten jelezve van, azokat a k�dr�szeket tilos megv�ltoztatni. Megv�ltoztat�s eset�n a vizsga sikertelen.
-	A vizsga megval�s�that� a main.cpp jelzett r�szein, illetve k�l�n .cpp, .h �s .hpp f�jlokban.
-	Mem�riasziv�rg�s l�te eset�n a vizsga el�gtelen (delete r�szek megv�ltoztat�s�val).
-	Online (internet, stackoverflow, diasorok stb.) �s offline (jegyzetek, k�nyvek) seg�deszk�z�k haszn�lhat�ak. Ugyanakkor a munka nem kollaborat�v, �gy m�s ember (padt�rs, Skype, Viber, Facebook stb.) seg�ts�ge kiz�rva.
-	A main.cpp-ben sok assert f�ggv�nyh�v�st l�that. Ez egy makr�, ami egy felt�telt vizsg�l �s annak nem teljes�l�se eset�n fut�sidej� hib�t dob. Az �n implement�ci�j�nak tesztel�s�re �s a jegy meghat�roz�s�ra szolg�l. Az assert felt�telek megv�ltoztat�sa TILOS. Az assert r�szek ideiglenesen az #define ELLENORZES makr� 0-ra �ll�t�s�val kapcsolhat�k ki, ami aj�nlott is a fejleszt�s sor�n.
-	A szab�lyok megs�rt�se a vizsga automatikus sikertelens�g�t vonja maga ut�n.
A le�rtakat meg�rtettem �s elfogadom:
N�v:
Neptun k�d:
Specifik�ci�
A Galaktikus Birodalom �j csillagrombol�kat k�sz�l �p�ttetni az �j k�s�rleti �zem�ben. Vader nagy�r szeretn� nyilv�ntart�sba venni az eddig elk�sz�lt rombol�kat, erre biztos�tott egy C++ programle�r�st.
2-es jegy�rt (SZINT_2)
-	Defini�lja a CsillagRombolo oszt�lyt! Az oszt�lynak legyen egy konstans neve. Az Imperial �s az Executor oszt�lyokat ebb�l sz�rmaztassa.
Konstansk�nt legyen defini�lva a maxim�lis/minim�lis leg�nys�g �s maxim�lis/minim�lis turb�l�zersz�m. Az oszt�ly jegyezze mennyi az aktu�lis leg�nys�g �s turb�l�zer.
A CsillagRombolo ne legyen p�ld�nyos�that�.
	-	Implement�lja a k�vetkez� absztrakt met�dust:
		-	int tuzero()
	-	Implement�lja a k�vetkez� seg�dmet�dusokat a CsillagRombolo oszt�lyhoz
		-	unsigned int getLegenyseg(): visszat�r az aktu�lis leg�nys�g sz�m�val
		-	std:string getName(): visszat�r a haj� nev�vel
		-	void addLegenyseg(unsigned int legenyseg): hozz�ad legenyseg sz�m� leg�nys�get
		-	void removeLegenyseg(unsigned int legenyseg): elt�volit legenyseg sz�m� leg�nys�get
		-	bool checkUzemkepes(): Vagyis: aktualis_legenyseg >= minimalis_legenyseg?
		-	unsigned int getMaxLegenyseg(): visszat�r a haj�hoz rendelhet� maxim�lis leg�nys�gsz�mmal
		-	unsigned int getMinLegenyseg(): visszat�r a haj�hoz rendelhet� minim�lis leg�nys�gsz�mmal
-	K�sz�tse el a k�t sz�rmaztatott csillagrombol� t�pus oszt�lydefin�ci�j�t: Imperial, Executor!
	-	Imperial-oszt�ly: Konstruktora megadja a nevet, aktu�lis leg�nys�gsz�mot �s aktu�lis turb�l�zersz�mot.
		-	Konstruktorban �ll�tsa be a minim�lis (29000) �s maxim�lis (45000) leg�nys�gsz�mot.
		-	A konstruktorban �ll�tsa be a minim�lis (40) �s maxim�lis (80) turb�l�zersz�mot.
		-	Megfelel� sz�m� leg�nys�g jelenl�te eset�n: T�zer� 100*turbolezerszam
	-	Executor-oszt�ly: rendelkezik ion �gy�kkal is, ezt jelezze konstans attrib�tumokkal. Konstruktora megadja a nevet, az aktu�lis leg�nys�gsz�mot, aktu�lis turb�l�zersz�mot �s aktu�lis ion�gy�sz�mot.
		-	A konstruktorban �ll�tsa be a minim�lis (1500) �s maxim�lis (2500) turb�l�zersz�mot.
		-	A konstruktorban �ll�tsa be a minim�lis (50000) �s maxim�lis (350000) leg�nys�gsz�mot.
		-	A konstruktorban �ll�tsa be a minim�lis (200) �s maxim�lis (300) ion�gy� sz�mot.
		-	Megfelel� sz�m� leg�nys�g jelenl�te eset�n a T�zer� 150*turbolezerszam+1000*ionagyuszam
-	K�sz�tsen egy flotta oszt�lyt, ami tartalmaz csillagrombol�kat! A Flotta csak egyszer p�ld�nyosulhat, legyen ez az oszt�ly singleton (ld. Singleton design pattern).
A flotta tartsa sz�mon a tartal�k leg�nys�get is, ami kezdetben 0.
	-	Konstruktora nem h�vhat� meg k�v�lr�l. Copy konstruktor �s assignment legyen letiltva.
	-	A getInstance() nev� statikus met�duson kereszt�l �rhet� el az egyetlen p�ld�nyra mutat� pointer. A freeInstance szabad�tsa fel az egyetlen p�ld�nyt
	-	Az addCsillagrombolo met�dussal lehet �j csillagrombol�t hozz�adni, egy CsillagRombolo mutat�t v�rva argumentumk�nt.
	-	A flott�b�l lek�rdezhet� egy csillagrombol� a nev�vel (getCsillagrombolo). Ekkor t�rjen vissza az adott csillagrombol�ra mutat� pointerrel.
	-	A flotta adja vissza, hogy aktu�lisan h�ny darab csillagrombol� van a flott�ban. (getQuantity)
	-	A flott�hoz lehessen hozz�rendelni tartal�k leg�nys�get, aminek bemen� param�tere egy pozit�v eg�sz sz�m (rendelTartalekLegenyseg). Lehessen lek�rdezni az aktu�lis tartal�kleg�nys�get!
3-as jegy�rt (SZINT_3)
-	Leg�nys�get lehessen hozz�adni a flotta egy csillagrombol�j�hoz a Flotta addLegenyseg met�dus�val a flott�hoz rendelt tartal�k leg�nys�g sz�m�b�l.
A met�dus a csillagrombol� nev�t �s egy darabsz�mot v�r!
-	Ugyanezt a f�ggv�nyt val�s�tsa meg �gy is, hogy egy csillagrombol�ra mutat� pointert v�r!
-	Minden hozz�rendel�s cs�kkentse a flott�hoz rendelt tartal�k leg�nys�g sz�m�t!
-	Ennek inverz�t is val�s�tsa meg, a Flotta tartalekbaHelyez met�dus�val. A met�dus v�rja a csillagrombol� nev�t �s a darabsz�mot!
-	Sz�molja azt is ki, hogy mekkora a flotta teljes leg�nys�ge! (getPersonnel) Ezt a csillagrombol�khoz aktu�lisan rendelt leg�nys�g �s a tartal�k leg�nys�g �sszeg�vel kapja meg.
4-es jegy�rt (SZINT_4)
-	Legyen a flott�nak egy checkImmobility met�dusa, ami ellen�rzi, hogy a flotta �zemk�pes-e (minden haj�n rendelkez�sre �ll-e minim�lis leg�nys�g).
T�rjen vissza az els� olyan haj�nak a mutat�j�val, ami nem �zemk�pes, vagy nullpointerrel, ha nincs ilyen!
-	A addLegenysegChecked met�dus ugyanazt val�s�tsa meg, mint a Flotta::addLegenyseg (pointer argumentum), viszont dobjon kiv�telt, ha hozz�rendel�ssel t�ll�pn�nk egy csillagrombol� 
kapacit�s�t(ErrorLegenyseg), vagy 0 al� cs�kkenne a flotta tartal�kos leg�nys�ge (ErrorTartalekos).
-	A tartalekbaHelyezChecked met�dus ugyanazt val�s�tsa meg, mint a tartalekbaHelyez (pointer argumentum) met�dus, viszont dobjon kiv�telt (ErrorLegenyseg), ha a csillagrombol� minim�lis leg�nys�gkapacit�sa al� menn�nk!
-	A flott�t�l elvonhat� tartal�k leg�nys�g (removeTartalekosChecked), ellen�rizze, hogy ne cs�kkenjen 0 al� a leg�nys�g - ha 0 al� cs�kkenne, dobjon kiv�telt (ErrorTartalekos)!
5-�s jegy�rt (SZINT_5)
-	A Flotta addCsillagromboloChecked met�dusa ellen�rizze, hogy a hozz�adand� csillagrombol� szerepel-e a flott�ban!
-	Amennyiben szerepel, a leg�nys�get rendelje hozz� a flott�ban szerepl� csillagrombol�hoz! M�s attrib�tum ne v�ltozzon!
-	Ehhez defini�ljon fel�l egy operator==-t, amivel ellen�rzi k�t csillagrombol� azonoss�g�t! K�t csillagrombol� azonos, ha ugyanaz a nev�k!
-	A csillagrombol�kat lehessen std::ostream-re ki�ratni! Ugyan�gy, egy flotta list�zhat� legyen, az �sszes csillagrombol� felsorol�s�val!  
A ki�rat�sban legyen benne a n�v, aktu�lis leg�nys�g, min. leg�nys�g, max. leg�nys�g!
*/


// Ez a resz a kivant szintnek megfeleloen valtoztathato (0 vagy 1)
#define SZINT_2 1
#define SZINT_3 1
#define SZINT_4 1
#define SZINT_5 0
// Ha fejleszt, erdemes kikapcsolni az ellenorzest
#define ELLENORZES 1
// Ezt a reszt TILOS megvaltoztatni
#include <iostream>
#include <cassert>
// END TILOS


// Ebben a reszben szabadon lehet include-olni tovabbi fajlokat
#include "CsillagRombolo.h"
#include "Executor.h"
#include "Flotta.h"
#include "Imperial.h"
#include "ErrorLegenyseg.h"
#include "ErrorTartalekos.h"


// END INCLUDE

// Ide kerulhet az implementacio

// A vizsgafeladatot tartalmazo fuggveny. Szabadon lehet kikommentelni egyes hivasokat.
// Az assert reszek nem valtoztathatok meg. Ezek megvaltoztatasa a vizsga sikertelenseget vonja maga utan.
void vizsga()
{
	std::cout << "VIZSGA 2020-01-14\n";
#if SZINT_2
	std::cout << "-------   2-es szint -----------\n";
	// Ellenorzeskent ezt a reszt kommentelje ki! Ha ezt kikommenteli es jol implementalta a feladatot, akkor a programnak nem szabad lefordulnia!
	// CsillagRombolo cs1;
	// Csillagrombolok peldanyositasa
	Imperial* vehement = new Imperial("Vehement", 37000, 80);
	Imperial* exactor = new Imperial("Exactor", 32000, 70);
	Imperial* devastator = new Imperial("Devastator", 28000, 35);
	Executor* executor = new Executor("Executor", 290000, 2500, 250);
#if ELLENORZES
	// Csillagrombolok ellenorzese
	std::cout << "Vehement legenysege: " << vehement->getLegenyseg() << ",\t elvart: 37 000\n";
	assert(vehement->getLegenyseg() == 37000);
	std::cout << "Exactor legenysege: " << exactor->getLegenyseg() << ",\t elvart: 32 000\n";
	assert(exactor->getLegenyseg() == 32000);
	std::cout << "Devastator legenysege: " << devastator->getLegenyseg() << ",\t elvart: 28 000\n";
	assert(devastator->getLegenyseg() == 28000);
	std::cout << "Executor legenysege: " << executor->getLegenyseg() << ",\t elvart: 290 000\n";
	assert(executor->getLegenyseg() == 290000);
	// Legenyseg hozzaadasa (Vehement)
	vehement->addLegenyseg(1000);
	std::cout << "Vehement legenysege (+1000): " << vehement->getLegenyseg() << ",\t elvart: 38000\n";
	assert(vehement->getLegenyseg() == 38000);
	vehement->removeLegenyseg(1000);
	std::cout << "Vehement legenysege (-1000): " << vehement->getLegenyseg() << ",\t elvart: 37000\n";
	assert(vehement->getLegenyseg() == 37000);
	// Legenyseg hozzaadasa (Executor)
	executor->addLegenyseg(1000);
	std::cout << "Executor legenysege (+1000): " << executor->getLegenyseg() << ",\t elvart: 291 000\n";
	assert(executor->getLegenyseg() == 291000);
	executor->removeLegenyseg(1000);
	std::cout << "Executor legenysege (-1000): " << executor->getLegenyseg() << ",\t elvart: 290 000\n";
	assert(executor->getLegenyseg() == 290000);
	// Sebzes ellenorzese
	assert(vehement->tuzero() == 100 * 80);
	assert(exactor->tuzero() == 100 * 70);
	assert(devastator->tuzero() == 0);
	assert(executor->tuzero() == 150 * 2500 + 250 * 1000);
	// Segedmetodusok ellenorzese
	assert(vehement->getMinLegenyseg() == 29000);
	assert(vehement->getMaxLegenyseg() == 45000);
	assert(executor->getMinLegenyseg() == 50000);
	assert(executor->getMaxLegenyseg() == 350000);
	// Uzemkepesseg
	std::cout << "Vehement uzemkepes: " << vehement->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(vehement->checkUzemkepes());
	std::cout << "Exactor uzemkepes: " << exactor->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(exactor->checkUzemkepes());
	std::cout << "Devastator uzemkepes: " << devastator->checkUzemkepes() << ",\t Elvart: 0\n";
	assert(!devastator->checkUzemkepes());
	std::cout << "Executor uzemkepes: " << executor->checkUzemkepes() << ",\t Elvart: 1\n";
	assert(executor->checkUzemkepes());
#endif
	// Flotta peldanyositasa
	// Ellenorzeskent ezt a reszt ha kikommenteli, es jol implementalta a feladatot, akkor a programnak nem szabad lefordulnia
	// Flotta flotta_peldany;
	// Flotta peldanyositasanak ellenorzese
	Flotta* flotta = Flotta::getInstance();
	Flotta* flotta2 = Flotta::getInstance();
#if ELLENORZES
	assert(flotta == flotta2);
	if (flotta == flotta2)
	{
		std::cout << "A kiserleti telepen csak egy flotta hozhato letre\n";
	}
	assert(flotta->getTartalekLegenyseg() == 0);
#endif
	// Csillagrombolok hozzaadasa
	flotta->addCsillagrombolo(vehement);
	flotta->addCsillagrombolo(exactor);
	flotta->addCsillagrombolo(devastator);
	flotta->addCsillagrombolo(executor);
	// Csillagrombolo kiolvasasa
#if ELLENORZES
	assert(flotta->getCsillagRombolo("Vehement") != nullptr);
	assert(flotta->getCsillagRombolo("Executor") != nullptr);
	assert(flotta->getCsillagRombolo("Exactor") != nullptr);
	assert(flotta->getCsillagRombolo("Devastator") != nullptr);
	assert(flotta->getCsillagRombolo("Millenium Falcon") == nullptr);
	assert(flotta->getCsillagRombolo("Vindicator") == nullptr);
#endif
	// Flotta tartalek legenyseg hozzaadasa
	flotta->rendelTartalekLegenyseg(20000);
#if ELLENORZES
	std::cout << "Flottahoz rendelt tartaleklegenyseg: " << flotta->getTartalekLegenyseg() << ", elvart legenyseg: 20 000\n";
	assert(flotta->getTartalekLegenyseg() == 20000);
#endif
	// Flotta ellenorzese
#if ELLENORZES
	std::cout << "Flottaban levo hajok: " << flotta->getQuantity() << ", elvart hajoszam: 4\n";
	assert(flotta->getQuantity() == 4);
	std::cout << "-----------------------\n";
#endif


#if SZINT_3	
	std::cout << "-------   3-as szint -----------\n";
	flotta->addLegenyseg("Executor", 10000);
	flotta->addLegenyseg(vehement, 1000);
#if ELLENORZES
	std::cout << "Vehement legenysegenek feltoltese a tartalekbol (+1000): " << vehement->getLegenyseg() << ", elvart: 38 000\n";
	assert(vehement->getLegenyseg() == 38000);
	std::cout << "Executor legenysegenek feltoltese a tartalekbol (+10000): " << executor->getLegenyseg() << ", elvart: 300 000\n";
	assert(executor->getLegenyseg() == 300000);
	std::cout << "Maradek tartaleklegenyseg " << flotta->getTartalekLegenyseg() << ", 9 000\n";
	assert(flotta->getTartalekLegenyseg() == 9000);
#endif
	flotta->tartalekbaHelyez("Executor", 10000);
#if ELLENORZES
	// Tartalekba helyezes utan
	std::cout << "Tartalekba helyezes az executorrol (-10000): " << executor->getLegenyseg() << ", elvart: 290 000\n";
	assert(executor->getLegenyseg() == 290000);
	assert(flotta->getTartalekLegenyseg() == 19000);
#endif
	// A szukseges legenyseg ellenorzese
	std::cout << "A flotta ellatasahoz szukseges legenyseg: " << flotta->getOsszesLegenyseg() << ", elvart teljes legenyseg: 407 000\n";
#if ELLENORZES
	assert(flotta->getOsszesLegenyseg() == 407000);
#endif
	std::cout << "------------------\n";
#endif // SZINT_3



#if SZINT_4
	std::cout << "-------   4-es szint -----------\n";
	// Ellenorizzuk mukodokepes-e a flotta
	std::cout << "A flotta nem mukodik, nincs eleg legenyseg, a kovetkezo hajon nincs eleg legenyseg: " << flotta->checkImmobility()->getName() << '\n';
#if ELLENORZES
	assert(flotta->checkImmobility() != nullptr);
	assert(flotta->checkImmobility() == devastator);
#endif
	// Hibakezeles ellenorzes
	bool error_not_thrown = false;
	std::cout << "Eljarasok helyessegenek tesztelese: " << '\n';
	try
	{
		flotta->addLegenysegChecked(vehement, 15000);
		error_not_thrown = true;
	}
	catch (ErrorLegenyseg e)
	{
		std::cout << "Tul sok embert kivanunk hozzaadni egy csillagrombolohoz!" << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
	try
	{
		flotta->addLegenysegChecked(executor, 25000);
		error_not_thrown = true;
	}
	catch (ErrorTartalekos e)
	{
		std::cout << "Nincs eleg tartalekos a flottaban!" << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
	try
	{
		flotta->tartalekbaHelyezChecked(executor, 250000);
		error_not_thrown = true;
	}
	catch (ErrorLegenyseg e)
	{
		std::cout << "A legenyseg tartalekbahelyezesevel mukodeskeptelenne valna egy csillagrombolo! " << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
	try
	{
		flotta->removeTartalekosChecked(90000);
		error_not_thrown = true;
	}
	catch (ErrorTartalekos e)
	{
		std::cout << "Nincs ennyi tartalekos a flottahoz rendelve!" << e.getMsg() << '\n';
	}
	assert(!error_not_thrown);
	// A metodusok tesztje utan adjunk hozza az egyetlen hianyzo hajohoz 
	// Ellenorizzuk mukodokepes-e a flotta	
	try
	{
		std::cout << "Devastator potlasa megfelelo mennyisegu legenyseggel: (+2000)\n";
		flotta->addLegenysegChecked(devastator, 2000);
		std::cout << "Devastator legenysege: " << devastator->getLegenyseg() << ", elvart legenyseg 30 000\n";
		assert(devastator->getLegenyseg() == 30000);
	}
	catch (ErrorTartalekos e)
	{
		std::cerr << "Nem szabadna semmi hibat dobni, valami gond van\n";
		assert(false);
		return;
	}
	catch (ErrorLegenyseg e)
	{
		std::cerr << "Nem szabadna semmi hibat dobni, valami gond van\n";
		assert(false);
		return;
	}
#if ELLENORZES
	assert(flotta->checkImmobility() == nullptr);

	std::cout << "A flotta mukodik, minden hajo uzemkepes" << '\n';
	std::cout << "------------------\n";
#endif
#endif // SZINT_4




#if SZINT_5
	std::cout << "-------   5-os szint -----------\n";
	Imperial* vehement2 = new Imperial("Vehement", 2000, 80);
	assert(*vehement == *vehement2);
	flotta->addCsillagromboloChecked(vehement2);
#if ELLENORZES
	std::cout << "A flotta hajoszama: " << flotta->getQuantity() << ", elvart hajoszam: 4\n";
	assert(flotta->getQuantity() == 4);
	std::cout << "A Vehement legenysege (+2000): " << vehement->getLegenyseg() << ", elvart legenyseg: 40000 \n";
	assert(vehement->getLegenyseg() == 40000);
#endif
	std::cout << *vehement << '\n';
	std::cout << *executor << '\n';
	std::cout << *flotta << '\n';
	std::cout << "------------------\n";

	delete vehement2;
#endif // SZINT_5


	delete vehement;
	delete exactor;
	delete devastator;
	delete executor;
	flotta->freeInstance();

#endif // SZINT_2
}

// Ezt a reszt TILOS megvaltoztatni
int main(int argc, char** argv)
{
	vizsga();
	return 0;
}
// END TILOS