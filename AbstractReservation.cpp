#include "AbstractReservation.h"
#include "ImprimeurReservation.h"
using namespace std;

AbstractReservation::AbstractReservation()
{
	_nom = "";
	_prix = 0;
	_visite = new ImprimeurReservation();
}

AbstractReservation& AbstractReservation::getReservation()
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
	std::cout << "------" << endl;
	reserv.accept(*reserv._visite);
	stream << "------" << endl;
	return stream;
}
