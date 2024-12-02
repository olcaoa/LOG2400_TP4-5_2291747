#include "Voyage.h"

std::string Voyage::imprimer()
{
	return "segment: \n" + imprimerEnfants();
}
