#include "Reservation.h"
#include "Journee.h"
#include "Segment.h"
#include "Voyage.h"

using namespace std;

int main() {

	Reservation firstReserv("meow", "woof", 100);
	Reservation secReserv("wagoo", "reee", 200);
	Journee firstDay;
	firstDay.ajouterReservation(&firstReserv);
	firstDay.ajouterReservation(&secReserv);
	Segment firstSeg;
	firstSeg.ajouterReservation(&firstDay);
	firstSeg.ajouterReservation(&firstDay);
	Voyage firstVoyage;
	firstVoyage.ajouterReservation(&firstSeg);

	cout << "reserv:" << endl << firstReserv << "prix: " << (int)firstReserv.getPrix() << "$$" << endl;
	cout << "day:" << endl << firstDay << "prix: " << (int)firstDay.getPrix() << "$$" << endl;
	cout << "seg:" << endl << firstSeg << "prix: " << (int)firstSeg.getPrix() << "$$" << endl;
	cout << "voyage:" << endl << firstVoyage << "prix: " << (int)firstVoyage.getPrix() << "$$" << endl;

	return 0;
}