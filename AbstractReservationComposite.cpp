#include "AbstractReservationComposite.h"
using namespace std;

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

std::string ReservationComposite::imprimerEnfants()
{
	string out = "";
	for (AbstractReservation* reserv : _reservations) {
		out += reserv->imprimer();
	}
	return out;
}
