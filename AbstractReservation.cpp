#include "AbstractReservation.h"
using namespace std;

std::string AbstractReservation::imprimer()
{
	return "� impl�menter";
}

const string& AbstractReservation::getNom() {
	return this->_nom;
}

const double& AbstractReservation::getPrix()
{
	return this->_prix;
}

std::ostream& operator<<(std::ostream& stream, AbstractReservation& reserv)
{
	stream << reserv.imprimer();
	return stream;
}
