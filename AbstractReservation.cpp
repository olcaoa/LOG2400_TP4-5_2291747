#include "AbstractReservation.h"
using namespace std;


const AbstractReservation& AbstractReservation::getReservation()
{
	return *this;
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
	stream << "not impl";
	return stream;
}
