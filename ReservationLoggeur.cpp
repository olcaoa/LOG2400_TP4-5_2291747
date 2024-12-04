#include "ReservationLoggeur.h"

ReservationLoggeur::ReservationLoggeur(AbstractReservation& r){
    _reservation = &r;
    decorer();
}

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
    ImprimeurLoggeur log;
    _reservation->accept(log);
}

AbstractReservation* ReservationLoggeur::clone() const
{
    return new ReservationLoggeur(*this->_reservation->clone());
}
