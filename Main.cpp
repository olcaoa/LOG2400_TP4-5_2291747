#include "Reservation.h"
#include "Voyage.h"
#include "LecteurFichier.h"
#include "BDORProxy.h"

using namespace std;

int main() {
	BDORProxy db(&BDOR::getInstance());
	Reservation firstReserv = db["Vols"][0];
	Reservation secReserv("second", "desc2", 200);
	Journee firstDay;
	firstDay.ajouterReservation(&firstReserv);
	firstDay.ajouterReservation(&secReserv);
	Segment firstSeg;
	firstSeg.ajouterReservation(&firstDay);
	firstSeg.ajouterReservation(&firstDay);
	Voyage firstVoyage;
	firstVoyage.ajouterReservation(&firstSeg);

	ImprimeurReservation imprimeur;
    firstVoyage.accept(imprimeur);

	cout << "reserv:" << endl << firstReserv << "prix: " << (int)firstReserv.getPrix() << "$$" << endl;
	// cout << "day:" << endl << firstDay << "prix: " << (int)firstDay.getPrix() << "$$" << endl;
	// cout << "seg:" << endl << firstSeg << "prix: " << (int)firstSeg.getPrix() << "$$" << endl;
	// cout << "voyage:" << endl << firstVoyage << "prix: " << (int)firstVoyage.getPrix() << "$$" << endl;

	return 0;
}