#include "Reservation.h"
#include "Voyage.h"
#include "LecteurFichier.h"
#include "BDORProxy.h"

using namespace std;

int main() {
	BDORProxy db;
	Reservation firstReserv = db["Hebergement"][0];
	Reservation secReserv(firstReserv);
	Journee firstDay;
	firstDay.ajouterReservation(&firstReserv);
	firstDay.ajouterReservation(&secReserv);
	Journee secDay(firstDay);
	Segment firstSeg("firstSeg");
	Segment secSeg(firstSeg);
	firstSeg.ajouterReservation(&firstDay);
	firstSeg.ajouterReservation(&firstDay);
	Voyage firstVoyage("firstV");
	firstVoyage.ajouterReservation(&firstSeg);
	Voyage secVoyage(firstVoyage);

	ImprimeurReservation imprimeur;
    secVoyage.accept(imprimeur);

	// cout << "reserv:" << endl << firstReserv << "prix: " << (int)firstReserv.getPrix() << "$$" << endl;
	// cout << "day:" << endl << firstDay << "prix: " << (int)firstDay.getPrix() << "$$" << endl;
	// cout << "seg:" << endl << firstSeg << "prix: " << (int)firstSeg.getPrix() << "$$" << endl;
	cout << "voyage:" << endl << firstVoyage << "prix: " << (int)firstVoyage.getPrix() << "$$" << endl;

	return 0;
}