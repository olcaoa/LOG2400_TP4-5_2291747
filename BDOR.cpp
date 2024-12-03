#include "BDOR.h"
#include "Reservation.h"
#include <stdexcept>

double BDOR::convertirPrix(const std::string& devise, double prix)
{
    return 0.0;
}

BDOR::BDOR() {
    importerReservations(lecteur);
}

BDOR& BDOR::getInstance() {
    static BDOR instance;
    return instance;
}

const std::vector<Reservation>& BDOR::acceder(std::string categorie) {
    if (reservations.find(categorie) != reservations.end()) {
        return reservations[categorie];
    } else {
        throw std::out_of_range("Catégorie de réservation non trouvée : " + categorie);
    }
}

double convertirPrix(const std::string& devise, double prix) {
        static const std::map<std::string, double> tauxConversion = {
            {"EURO", 1.5},
            {"USD", 1.3},
            {"CDN", 1.0}
        };

        auto it = tauxConversion.find(devise);
        if (it != tauxConversion.end()) {
            return prix * it->second;
        }
    return prix;
}

void BDOR::importerReservations(LecteurFichier& lecteur) {
    for (string category : lecteur.cles) {
        vector<string> noms = lecteur.obtenirDonnees(category, "m_nom");
        vector<string> prix = lecteur.obtenirDonnees(category, "m_prixUnitaire");
        if (category == lecteur.cles[0]) {
            auto desc = lecteur.obtenirDonnees(category, "m_jourPrevuDepart");
            for (int i = 0; i < noms.size(); i++) {
                reservations[category].push_back(Reservation(noms[i], desc[i], stod(prix[i])));
            }
        }
        else {
            for (int i = 0; i < noms.size(); i++) {
                reservations[category].push_back(Reservation(noms[i], "A voir", stod(prix[i])));
            }
        }
    }
}
       

