#include "ReservationLoggeur.h"
#include <filesystem>

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
    ImprimeurLoggeur log;
    _reservation->accept(log);

    ofstream fichier(nomFichier);
    fichier << log.lecture.str();
}

AbstractReservation* ReservationLoggeur::clone() const
{
    return new ReservationLoggeur(*this->_reservation->clone());
}
