#include "CsillagRombolo.h"

CsillagRombolo::~CsillagRombolo()
{
}

unsigned int CsillagRombolo::getLegenyseg()
{
	return akt_legenyseg;
}

std::string CsillagRombolo::getName()
{
	return name;
}

void CsillagRombolo::addLegenyseg(unsigned int legenyseg)
{
	akt_legenyseg += legenyseg;
}

void CsillagRombolo::removeLegenyseg(unsigned int legenyseg)
{
	akt_legenyseg -= legenyseg;
}

bool CsillagRombolo::checkUzemkepes()
{
	bool igaz = false;
	if (akt_legenyseg > minlegeny)
	{
		igaz = true;
	}
	return igaz;
}

unsigned int CsillagRombolo::getMaxLegenyseg()
{
	return maxlegeny;
}

unsigned int CsillagRombolo::getMinLegenyseg()
{
	return minlegeny;
}
