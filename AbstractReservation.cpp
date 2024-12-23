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

const double AbstractReservation::getPrix()
{
	return this->_prix;
}

void AbstractReservation::setPrix(double prix)
{
	_prix = prix;
}

const void AbstractReservation::setDescription(std::string desc)
{
	this->_description = desc;
}

std::ostream& operator<<(std::ostream& stream, AbstractReservation& reserv)
{
	reserv.accept(*reserv._visite);
	stream << dynamic_cast<ImprimeurReservation*>(reserv._visite)->lecture.str();
	return stream;
}
