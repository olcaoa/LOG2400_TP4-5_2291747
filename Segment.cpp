#include "Segment.h"

std::string Segment::imprimer()
{
    return "journee: \n" + imprimerEnfants();
}
