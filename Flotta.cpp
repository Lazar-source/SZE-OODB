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
/*A addLegenysegChecked met�dus ugyanazt val�s�tsa meg, mint a Flotta::addLegenyseg(pointer argumentum), viszont dobjon kiv�telt, ha hozz�rendel�ssel t�ll�pn�nk egy csillagrombol�
kapacit�s�t(ErrorLegenyseg), vagy 0 al� cs�kkenne a flotta tartal�kos leg�nys�ge(ErrorTartalekos).
- A tartalekbaHelyezChecked met�dus ugyanazt val�s�tsa meg, mint a tartalekbaHelyez(pointer argumentum) met�dus, viszont dobjon kiv�telt(ErrorLegenyseg), ha a csillagrombol� minim�lis
leg�nys�gkapacit�sa al� menn�nk!
- A flott�t�l elvonhat� tartal�k leg�nys�g(removeTartalekosChecked), ellen�rizze, hogy ne cs�kkenjen 0 al� a leg�nys�g - ha 0 al� cs�kkenne, dobjon kiv�telt(ErrorTartalekos)!*/
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
		throw(ErrorTartalekos("Any�d"));
	}
	else
	{
		tartalek_legenyseg -= db;
	}

}


