#include "Flotta.h"

void Flotta::addCsillagrombolo(CsillagRombolo * rombolo)
{
	g1.push_back(rombolo);
}

CsillagRombolo * Flotta::getCsillagRombolo(std::string n)
{
	CsillagRombolo* rombolo=nullptr;
	std::vector<CsillagRombolo*>::iterator it;
	for (it = g1.begin(); it < g1.end(); it++)
	{
		if ((*it)->getName() == n)
		{
			rombolo = (*it);
		}
	}
	return rombolo;
	
}

unsigned int Flotta::getQuantity()
{
	unsigned int db = 0;
	std::vector<CsillagRombolo*>::iterator it;
	for (it = g1.begin(); it < g1.end(); it++)
	{
		db++;
	}
	return db;
}

void Flotta::rendelTartalekLegenyseg(unsigned int legenyseg)
{
	tartalek_legenyseg += legenyseg;
}

unsigned int Flotta::getTartalekLegenyseg()
{
	return tartalek_legenyseg;
}

void Flotta::addLegenyseg(std::string n, unsigned int db)
{
	std::vector<CsillagRombolo*>::iterator it;
	for (it = g1.begin(); it < g1.end(); it++)
	{
		if ((*it)->getName() == n)
		{
			(*it)->addLegenyseg(db);
			tartalek_legenyseg -= db;
		}
	}
}

void Flotta::addLegenyseg(CsillagRombolo * rombolo, unsigned int db)
{
	std::vector<CsillagRombolo*>::iterator it;
	for (it = g1.begin(); it < g1.end(); it++)
	{
		if ((*it)->getName() == rombolo->getName())
		{
			(*it)->addLegenyseg(db);
			tartalek_legenyseg -= db;
		}
	}
}

void Flotta::tartalekbaHelyez(std::string n, unsigned int db)
{
	std::vector<CsillagRombolo*>::iterator it;
	for (it = g1.begin(); it < g1.end(); it++)
	{
		if ((*it)->getName() == n)
		{
			(*it)->removeLegenyseg(db);
			tartalek_legenyseg += db;
		}
	}
}

unsigned int Flotta::getOsszesLegenyseg()
{
	unsigned int db =0;
	std::vector<CsillagRombolo*>::iterator it;
	for (it = g1.begin(); it < g1.end(); it++)
	{

		db+=(*it)->getLegenyseg();
	}
	db += tartalek_legenyseg;
	return db;
}

CsillagRombolo * Flotta::checkImmobility()
{
	CsillagRombolo* rombolo = nullptr;
	std::vector<CsillagRombolo*>::iterator it;
	for (it = g1.begin(); it < g1.end(); it++)
	{
		if ((*it)->getLegenyseg() < (*it)->getMinLegenyseg())
		{
			rombolo = (*it);
			break;
		}
	}
	return rombolo;
}
/*A addLegenysegChecked metódus ugyanazt valósítsa meg, mint a Flotta::addLegenyseg(pointer argumentum), viszont dobjon kivételt, ha hozzárendeléssel túllépnénk egy csillagromboló
kapacitását(ErrorLegenyseg), vagy 0 alá csökkenne a flotta tartalékos legénysége(ErrorTartalekos).
- A tartalekbaHelyezChecked metódus ugyanazt valósítsa meg, mint a tartalekbaHelyez(pointer argumentum) metódus, viszont dobjon kivételt(ErrorLegenyseg), ha a csillagromboló minimális
legénységkapacitása alá mennénk!
- A flottától elvonható tartalék legénység(removeTartalekosChecked), ellenõrizze, hogy ne csökkenjen 0 alá a legénység - ha 0 alá csökkenne, dobjon kivételt(ErrorTartalekos)!*/
void Flotta::addLegenysegChecked(CsillagRombolo * rombolo, unsigned int db)
{
	int temp = db - tartalek_legenyseg;
	std::vector<CsillagRombolo*>::iterator it;
	for (it = g1.begin(); it < g1.end(); it++)
	{

		
			if ((*it)==rombolo)
			{
				if (((*it)->getLegenyseg() + db) > (*it)->getMaxLegenyseg())
				{
					throw(ErrorLegenyseg("Anyad1"));

				}

				else
				{
					if (temp > 0)
					{
						throw(ErrorTartalekos("Anyad2"));
					}
					else
					{
						(*it)->addLegenyseg(db);
						tartalek_legenyseg -= db;
					}
				}

			}
		
	}
}

void Flotta::tartalekbaHelyezChecked(CsillagRombolo * rombolo, unsigned int db)
{
	std::vector<CsillagRombolo*>::iterator it;
	for (it = g1.begin(); it < g1.end(); it++)
	{
		if ((*it)==rombolo)
		{
			if (((*it)->getLegenyseg() - db) < (*it)->getMinLegenyseg())
			{
				throw(ErrorLegenyseg(" Anyad"));
			}
			else
			{

				(*it)->removeLegenyseg(db);
				tartalek_legenyseg += db;
			}
		}
	}
}

void Flotta::removeTartalekosChecked(unsigned int db)
{
	int temp = db - tartalek_legenyseg;
	if ( temp> 0)
	{
		throw(ErrorTartalekos("Anyád"));
	}
	else
	{
		tartalek_legenyseg -= db;
	}

}


