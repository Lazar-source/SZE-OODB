#include "Imperial.h"

int Imperial::tuzero()
{
	if (akt_legenyseg > minlegeny)
	{
		return 100 * akt_turbolezer;
	}
	else
	{
		return 0;
	}
}
