#include "BDOR.h"
#include "Reservation.h"
#include <stdexcept>

BDOR::BDOR() {}

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

void BDOR::importerReservations(const LecteurFichier& lecteur) {
    for (const auto& categorie : lecteur._donneesParCategorie) {
        std::vector<Reservation> reservationsImportees;
        
        for (const auto& typeDonnee : categorie.second) {
            if (categorie.first == "Vols") {
                for (size_t i = 0; i < typeDonnee.second.size(); i += 15) {
                    std::string nom = typeDonnee.second[i];
                    std::string description = typeDonnee.second[i + 3] + " -> " + typeDonnee.second[i + 4]; // Lieu de départ et d'arrivée
                    double prix = std::stod(typeDonnee.second[i + 13]);
                    std::string devise = typeDonnee.second[i + 14];

                    prix = convertirPrix(devise, prix);
                    Reservation reservation(nom, description, prix);
                    reservationsImportees.push_back(reservation);
                }
            } else if (categorie.first == "Hebergements" || categorie.first == "Excursions") {
                for (size_t i = 0; i < typeDonnee.second.size(); i += 7) {
                    std::string nom = typeDonnee.second[i];
                    std::string description = typeDonnee.second[i + 1]; // L'endroit
                    double prix = std::stod(typeDonnee.second[i + 5]); // Prix
                    std::string devise = typeDonnee.second[i + 6]; // Devise

                    Reservation reservation(nom, description, prix);
                    reservationsImportees.push_back(reservation);
                }
            }
        }
        reservations[categorie.first] = reservationsImportees;
    }
}

