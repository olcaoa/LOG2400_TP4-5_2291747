#include "ImprimeurLoggeur.h"
#include "Reservation.h"

void ImprimeurLoggeur::visit(Reservation& reservation)
{
	using namespace std;
	ofstream fichierTexteOut("Log.txt");
	fichierTexteOut << "Log test creation de Reservation: "
		<< reservation.getNom() << " " << "prix: " << reservation.getPrix()
		<< endl;
}

void ImprimeurLoggeur::visit(Journee& journee)
{
}

void ImprimeurLoggeur::visit(Segment& segment)
{
}

void ImprimeurLoggeur::visit(Voyage& voyage)
{
}
