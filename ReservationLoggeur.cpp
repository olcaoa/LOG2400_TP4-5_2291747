#include "ReservationLoggeur.h"

const std::string& ReservationLoggeur::getNom()
{
    return _reservation->getNom();
}

void ReservationLoggeur::accept(VisiteurImprimeur& visiteur)
{
    return _reservation->accept(visiteur);
}

void ReservationLoggeur::decorer()
{
}
