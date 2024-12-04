#include "ReservationCommentee.h"
#include <algorithm>

void ReservationCommentee::decorer(){}

ReservationCommentee::ReservationCommentee(Reservation& r)
{
    _reservation = &r;
}

ReservationCommentee& ReservationCommentee::getReservation(std::string nom)
{
    return *dynamic_cast<ReservationCommentee*>(ReservationComposite::getReservation(nom));
}

const std::string& ReservationCommentee::getNom()
{
    return _reservation->getNom();
}

void ReservationCommentee::accept(VisiteurImprimeur& visiteur)
{
    return _reservation->accept(visiteur);
}

AbstractReservation* ReservationCommentee::clone() const
{
    return new ReservationCommentee(*dynamic_cast<Reservation*>(_reservation->clone()));;
}

void ReservationCommentee::ajouterCommentaire(std::string comm) {
    commentaires.push_back(comm);
}

void ReservationCommentee::enleverCommentaire(std::string comm) {
    auto it = std::find(commentaires.begin(), commentaires.end(), comm);
    if (it != commentaires.end()) {
        commentaires.erase(it);
    }
}

std::vector<std::string> ReservationCommentee::trouverCommentatires(std::string comm)
{
    using namespace std;
    vector<string> commentairesTrouves;
    for (string commIt : commentaires) {
        if (commIt.find(comm) != std::string::npos) {
            commentairesTrouves.push_back(commIt);
        }
    }
    return commentairesTrouves;
}
