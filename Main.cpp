#include "Reservation.h"
#include "Voyage.h"
#include "LecteurFichier.h"
#include "BDORProxy.h"
#include "ReservationLoggeur.h"
#include "ReservationCommentee.h"

using namespace std;

int main() {
    BDORProxy db;

    Voyage voyageDora("Voyage de Dora");

    Segment segmentFrance("France 1ere partie");
    Segment segmentPortugal("Portugal");
    Segment segmentFrance2("France 2e partie");

    Journee journee1(26, 10, 2024);
    Reservation* reserv1 = &db["Vols"][0];
    journee1.ajouterReservation(*reserv1);
    segmentFrance.ajouterJournee(journee1);

    Journee journee2(27, 10, 2024);
    Reservation* reserv2 = &db["Hebergement"][0];
    journee2.ajouterReservation(*reserv2);
    segmentFrance.ajouterJournee(journee2);

    Journee journee3(28, 10, 2024);
    Reservation* reserv3 = &db["Excursions"][0];
    Reservation* reserv4 = &db["Hebergement"][1];
    journee3.ajouterReservation(*reserv3);
    journee3.ajouterReservation(*reserv4);
    segmentFrance.ajouterJournee(journee3);

    Journee journee4(29, 10, 2024);
    Reservation* reserv5 = &db["Vols"][1];
    Reservation* reserv6 = &db["Hebergement"][2];
    journee4.ajouterReservation(*reserv5);
    journee4.ajouterReservation(*reserv6);
    segmentPortugal.ajouterJournee(journee4);

    Journee journee5(30, 10, 2024);
    Reservation* reserv7 = &db["Excursions"][1];
    Reservation* reserv8 = &db["Hebergement"][3];
    journee5.ajouterReservation(*reserv7);
    journee5.ajouterReservation(*reserv8);
    segmentPortugal.ajouterJournee(journee5);

    Journee journee6(31, 10, 2024);
    Reservation* reserv9 = &db["Vols"][2];
    journee6.ajouterReservation(*reserv9);
    segmentPortugal.ajouterJournee(journee6);

    Journee journee7(31, 10, 2024);
    Reservation* reserv10 = &db["Hebergement"][4];
    journee7.ajouterReservation(*reserv10);
    segmentFrance2.ajouterJournee(journee7);

    voyageDora.ajouterSegment(segmentFrance);
    voyageDora.ajouterSegment(segmentPortugal);
    voyageDora.ajouterSegment(segmentFrance2);
	
    cout << voyageDora << endl;

    Voyage voyageDiego(voyageDora, "Voyage de Diego");
    Segment& aEnlever = voyageDiego.getSegment("Portugal");
    voyageDiego.enleverSegment(aEnlever);
    Segment segmentEspagne("Espagne");
    voyageDiego.ajouterSegment(segmentEspagne);

    Journee journeeEspagne1(29, 10, 2024);
    Reservation* reservEspagne1 = &db["Vols"][3];
    Reservation* reservEspagne2 = &db["Hebergement"][5];
    journeeEspagne1.ajouterReservation(*reservEspagne1);
    journeeEspagne1.ajouterReservation(*reservEspagne2);
    segmentEspagne.ajouterJournee(journeeEspagne1);

    Journee journeeEspagne2(30, 10, 2024);
    Reservation* reservEspagne3 = &db["Excursions"][2];
    Reservation* reservEspagne4 = &db["Hebergement"][6];
    journeeEspagne2.ajouterReservation(*reservEspagne3);
    journeeEspagne2.ajouterReservation(*reservEspagne4);
    segmentEspagne.ajouterJournee(journeeEspagne2);

    Journee journeeEspagne3(31, 10, 2024);
    Reservation* reservEspagne5 = &db["Vols"][4];
    journeeEspagne3.ajouterReservation(*reservEspagne5);
    segmentEspagne.ajouterJournee(journeeEspagne3);

    cout << voyageDiego << endl;

    Voyage voyageAlicia(voyageDiego, "Voyage d'Alicia");


    double totalDora = voyageDora.getPrix();
    double totalDiego = voyageDiego.getPrix();
    double totalAlicia = voyageAlicia.getPrix();


    cout << "Total des frais pour le Voyage de Dora ($ CA): " << totalDora << endl;
    cout << "Total des frais pour le Voyage de Diego ($ CA): " << totalDiego << endl;
    cout << "Total des frais pour le Voyage d'Alicia ($ CA): " << totalAlicia << endl;

    cout << "--- Debut de la sortie du TP5" << endl; // Voir ReservationLoggeur.cpp pour source du probleme commenté
    
    Reservation addReserv1("Reservation Restaurant de l'hôtel Stella pour le 27 octobre 2024 à 19h.", "", 0);
    reserv2->ajouterReservation(&addReserv1);
    ReservationCommentee commentReserv1(*reserv1);
    commentReserv1.ajouterCommentaire("Excellent Service!");

    db.ajusterPrix(1.03);
    db.ajouterRabais(*reserv7, "Excursions", 0.95);

    ReservationLoggeur loggerDora(voyageDora);
    ReservationLoggeur loggerDiego(voyageDiego);
    ReservationLoggeur loggerAlicia(voyageAlicia);




    std::cout << "Total du nombre d'offres de reservations dans la BDOR: " << db.getNombreOffres() << std::endl;
    return 0;
}
