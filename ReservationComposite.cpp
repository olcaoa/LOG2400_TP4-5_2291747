#include "ReservationComposite.h"
using namespace std;

ReservationComposite::ReservationComposite() : AbstractReservation() {}

double ReservationComposite::calculerPrix()
{
	for (auto reservation : _reservations) {
		_prix += reservation->getPrix();
	}
	return _prix;
}

const double ReservationComposite::getPrix()
{
	calculerPrix();
	return _prix;
}

AbstractReservation* ReservationComposite::getReservation(std::string nom)
{
	auto position = find_if(_reservations.begin(), _reservations.end(), [nom](AbstractReservation* r) {
		return r->getNom() == nom;
		});
	return *position;
}

void ReservationComposite::ajouterReservation(AbstractReservation* r)
{
	_reservations.push_back(r);
}

void ReservationComposite::enleverReservation(AbstractReservation* r)
{
	auto position = find(_reservations.begin(), _reservations.end(), r);
	_reservations.erase(position);
}

std::vector<AbstractReservation*> ReservationComposite::obtenirReservations()
{
	return _reservations;
}

void ReservationComposite::accept(VisiteurImprimeur& visiteur) {
    for (AbstractReservation* reservation : _reservations) {
        reservation->accept(visiteur);
    }
}

