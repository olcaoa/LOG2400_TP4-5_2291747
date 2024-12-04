#include "ReservationComposite.h"
using namespace std;

ReservationComposite::ReservationComposite() : AbstractReservation() {}

double ReservationComposite::calculerPrix()
{

	double total = 0;
	for (auto reservation : _reservations) {
		total += reservation->getPrix();
	}
	return total;
}

const double ReservationComposite::getPrix()
{
	return calculerPrix();
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

