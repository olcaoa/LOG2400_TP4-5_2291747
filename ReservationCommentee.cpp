#include "ReservationCommentee.h"
#include <algorithm>

ReservationCommentee& ReservationCommentee::getReservation(std::string nom)
{
    return *dynamic_cast<ReservationCommentee*>(ReservationComposite::getReservation(nom));
}

void ReservationCommentee::ajouterCommentaire(std::string& comm) {
    commentaires.push_back(comm);
}

void ReservationCommentee::enleverCommentaire(std::string& comm) {
    auto it = std::find(commentaires.begin(), commentaires.end(), comm);
    if (it != commentaires.end()) {
        commentaires.erase(it);
    }
}

std::vector<std::string> ReservationCommentee::trouverCommentatires(std::string& comm)
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
