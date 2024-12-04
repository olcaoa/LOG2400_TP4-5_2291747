#include "ReservationLoggeur.h"
#include <filesystem>

ReservationLoggeur& ReservationLoggeur::getReservation(std::string nom)
{
    return *dynamic_cast<ReservationLoggeur*>(ReservationComposite::getReservation(nom));
}

ReservationLoggeur::ReservationLoggeur(AbstractReservation& r){
    _reservation = &r;
    decorer();
}

const std::string& ReservationLoggeur::getNom()
{
    return _reservation->getNom();
}

void ReservationLoggeur::accept(VisiteurImprimeur& visiteur)
{
    return _reservation->accept(visiteur);
}

void ReservationLoggeur::decorer()
{
    using namespace std;
    using namespace std::filesystem;
    path chemin = path(".")/"Logs";
    directory_entry dir(chemin);
    if (!dir.exists()) {
        create_directory(dir);
    }
    path nomFichier = chemin / (getNom() + ".txt");
    ImprimeurReservation log;
    _reservation->accept(log);

    ofstream fichier(nomFichier,ios::app);
    fichier << log.lecture.str();
    fichier.close();
}

AbstractReservation* ReservationLoggeur::clone() const
{
    return new ReservationLoggeur(*this->_reservation->clone());
}
