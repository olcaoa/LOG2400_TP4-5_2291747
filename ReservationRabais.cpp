#include "ReservationRabais.h"
#include "Reservation.h"

ReservationRabais& ReservationRabais::getReservation(std::string nom)
{
	return *dynamic_cast<ReservationRabais*>(ReservationComposite::getReservation(nom));
}

ReservationRabais::ReservationRabais(Reservation& r, double rabais)
{
	_reservation = &r;
	_rabais = rabais;
}

const std::string& ReservationRabais::getNom()
{
	return _reservation->getNom();
}

void ReservationRabais::accept(VisiteurImprimeur& visiteur)
{
	return _reservation->accept(visiteur);
}

void ReservationRabais::decorer(){}

AbstractReservation* ReservationRabais::clone() const { 
	return new ReservationRabais(*dynamic_cast<Reservation*>(_reservation->clone()), _rabais);
}

const double ReservationRabais::getPrix()
{
	return _reservation->getPrix()*_rabais;
}

