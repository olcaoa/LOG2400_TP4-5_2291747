#include "ReservationComposite.h"
using namespace std;

ReservationComposite::ReservationComposite() : AbstractReservation() {}

ReservationComposite::ReservationComposite(const ReservationComposite& autreComposite)
    : AbstractReservation(autreComposite)
{
    for (auto reservation : autreComposite._reservations) {
        this->_reservations.push_back(reservation->clone());
    }
}

double ReservationComposite::calculerPrix()
{

	double total = 0;
	for (auto reservation : _reservations) {
		total += reservation->getPrix();
	}
	return total;
}

const double& ReservationComposite::getPrix()
{
	return calculerPrix();
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

std::vector<AbstractReservation*>& ReservationComposite::obtenirReservations()
{
	return _reservations;
}

void ReservationComposite::accept(VisiteurImprimeur& visiteur) {
    for (AbstractReservation* reservation : _reservations) {
        reservation->accept(visiteur);
    }
}

AbstractReservation* ReservationComposite::clone() const {
    ReservationComposite* clone = new ReservationComposite(*this);
    for (auto reservation : _reservations) {
        clone->ajouterReservation(reservation->clone());
    }
    return clone;
}