#include "IterateurLecteur.h"
#include <stdexcept>
#include <sstream>

IterateurLecteurFichier::IterateurLecteurFichier(LecteurFichier& lecteur, const std::string& categorie)
    : lecteurFichier(lecteur), categorie(categorie), index(0) {}

bool IterateurLecteurFichier::aSuivant() const {
    auto& donnees = lecteurFichier.obtenirDonnees(categorie, "m_nom");
    return index < donnees.size();
}

Reservation* IterateurLecteurFichier::suivant() {
    if (!aSuivant()) {
        throw std::out_of_range("Plus de données disponibles.");
    }

    auto& noms = lecteurFichier.obtenirDonnees(categorie, "m_nom");
    auto& descriptions = lecteurFichier.obtenirDonnees(categorie, "m_jourPrevuDepart");
    auto& prixs = lecteurFichier.obtenirDonnees(categorie, "m_prixUnitaire");
    auto& devises = lecteurFichier.obtenirDonnees(categorie, "m_devise");

    std::string nom = noms[index];
    std::string description = descriptions[index];
    double prix = convertirPrix(prixs[index], devises[index]);

    ++index;

    return new Reservation(nom, description, prix);
}

double IterateurLecteurFichier::convertirPrix(const std::string& prix, const std::string& devise) {
    try {
        double prixDouble = std::stod(prix);
        if (tauxDeChange.find(devise) != tauxDeChange.end()) {
            return prixDouble * tauxDeChange.at(devise);
        } else {
            throw std::invalid_argument("Devise inconnue: " + devise);
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Erreur de conversion du prix : " + std::string(e.what()));
    }
}

void IterateurLecteurFichier::reinitialiser() {
    index = 0;
}
