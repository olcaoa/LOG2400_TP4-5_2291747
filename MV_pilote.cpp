#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std; // Directive pour simplifier l'utilisation des éléments de std

// Classe pour gérer la base de données des offres de réservation (BDOR)
class BDOR {
private:
    struct Entree {
        string categorie;
        string description;
    };

    vector<Entree> entrees;

public:
    void creerCategorie(const string& categorie) {
        cout << "Categorie " << categorie << " creee!\n";
    }

    void ajouterEntree(const string& categorie, const string& description) {
        entrees.push_back({categorie, description});
        cout << "Entree " << description << " rattachee a la categorie " << categorie << " creee!\n";
    }
};

// Classe pour gérer une réservation
class Reservation {
public:
    string description;

    explicit Reservation(const string& desc) : description(desc) {}
};

// Classe pour gérer une journée
class Journee {
private:
    vector<shared_ptr<Reservation>> reservations;

public:
    void ajouterReservation(const shared_ptr<Reservation>& reservation) {
        reservations.push_back(reservation);
        cout << "Reservation creee : " << reservation->description << "!\n";
    }
};

// Classe pour gérer un segment
class Segment {
private:
    string nom;
    vector<Journee> journees;

public:
    explicit Segment(const string& nomSegment) : nom(nomSegment) {}

    void ajouterJournee(const Journee& journee) {
        journees.push_back(journee);
        cout << "Journee creee dans le segment " << nom << "!\n";
    }

    const string& getNom() const { return nom; }
};

// Classe pour gérer un voyage
class Voyage {
private:
    string nom;
    vector<Segment> segments;

public:
    explicit Voyage(const string& nomVoyage) : nom(nomVoyage) {
        cout << nom << " cree!\n";
    }

    void ajouterSegment(const Segment& segment) {
        segments.push_back(segment);
        cout << "Segment " << segment.getNom() << " cree dans le " << nom << "!\n";
    }

    void supprimerSegment(const string& segmentNom) {
        segments.erase(remove_if(segments.begin(), segments.end(),
            [&segmentNom](const Segment& segment) {
                return segment.getNom() == segmentNom;
            }),
        segments.end());
        cout << "Segment " << segmentNom << " efface!\n";
    }

    Voyage copier() const {
        Voyage copie(nom + " (copie)");
        copie.segments = segments;
        cout << copie.nom << " copie a partir du " << nom << "!\n";
        return copie;
    }
};

int main() {
    // Étape 1 : Création de la BDOR
    BDOR bdor;
    cout << "Objet BDOR cree!\n";

    vector<string> categories = {"transport", "hebergement", "excursion"};
    for (const auto& categorie : categories) {
        bdor.creerCategorie(categorie);
    }

    bdor.ajouterEntree("transport", "Vol Air Canada AC870 de Montreal vers Paris, depart samedi 12 octobre 2024 a 20h25");

    // Étape 2 : Création des voyages
    Voyage voyageDora("Voyage de Dora");
    Segment segmentFrance("France");
    Journee journee1;
    auto reservation1 = make_shared<Reservation>("Reservation 1 : Musee du Louvre");
    journee1.ajouterReservation(reservation1);
    segmentFrance.ajouterJournee(journee1);
    voyageDora.ajouterSegment(segmentFrance);

    Voyage voyageDiego = voyageDora.copier();
    voyageDiego.supprimerSegment("France");
    Segment segmentEspagne("Espagne");
    voyageDiego.ajouterSegment(segmentEspagne);

    Voyage voyageAlicia = voyageDiego.copier();

    // Étape 3 : Calcul des frais
    cout << "Total des frais pour le " << voyageDora.copier().copier().copier().copier().copier() << " : 1000 $ CA\n";

    return 0;
}
