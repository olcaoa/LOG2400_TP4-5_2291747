#include "ImprimeurLoggeur.h"
#include "BDOR.h"
#include "Voyage.h"

void ImprimeurLoggeur::visit(Reservation& reservation)
{
	using namespace std;
	lecture << "Log test creation de Reservation: "
		<< reservation.getNom() << " " << "prix: " << reservation.getPrix()
		<< endl;
}

void ImprimeurLoggeur::visit(Journee& journee)
{
	using namespace std;
	lecture << "Log test creation de Voyage: "
		<< journee.getNom() << " " << "prix: " << journee.getPrix()
		<< endl;
}

void ImprimeurLoggeur::visit(Segment& segment)
{
	using namespace std;
	lecture << "Log test creation de Voyage: "
		<< segment.getNom() << " " << "prix: " << segment.getPrix()
		<< endl;
}

void ImprimeurLoggeur::visit(Voyage& voyage)
{
	using namespace std;
	lecture << "Log test creation de Voyage: "
		<< voyage.getNom() << " " << "prix: " << voyage.getPrix()
		<< endl;
}
