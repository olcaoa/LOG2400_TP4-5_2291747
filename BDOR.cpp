#include "BDOR.h"
#include "Reservation.h"
#include <stdexcept>
#include <filesystem>

void BDOR::accept(ImprimeurReservation& log)
{
    using namespace std;
    using namespace std::filesystem;
    path chemin = path(".") / "Logs";
    directory_entry dir(chemin);
    if (!dir.exists()) {
        create_directory(dir);
    }
    path nomFichier = chemin / ("AjustementPrix.txt");
    ofstream fichier(nomFichier, ios::app);
    log.visit(*this);
    fichier << log.lecture.str();
}

double BDOR::convertirPrix(const std::string& devise, double prix)
{
    return 0.0;
}

void BDOR::ajusterPrix(double facteur)
{
    using namespace std;
    for (auto paire : reservations) {
        for (auto reservation : paire.second) {
            reservation.setPrix(reservation.getPrix() * facteur);
        }
    }
    dernierFacteurAjustement = facteur;
    ImprimeurReservation log;
    accept(log);

}

void BDOR::ajouterRabais(Reservation& r, std::string categorie, double rabais)
{
    auto position = find_if(reservations[categorie].begin(), reservations[categorie].end(), [r](Reservation reservIt) {
            return reservIt.comparerReservations(r);
        });
    *position = ReservationRabais(r, rabais);
    nombreOffres +=1;
}

void BDOR::liberer()
{
    for (auto r : this->reservations) {
        r.second.clear();
        r.second.shrink_to_fit();
    }
    reservations.clear();

}

BDOR::~BDOR()
{
    liberer();
}

BDOR::BDOR() {
    cout << "Objet BDOR cree!" << endl;
    _lecteur = new LecteurFichier;
    importerReservations(_lecteur);
}

BDOR& BDOR::getInstance() {
    static BDOR instance;
    if (instance.reservations.size() == 0) {
        instance.importerReservations(new LecteurFichier);
    }
    return instance;
}

std::vector<Reservation>& BDOR::acceder(std::string categorie) {
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

void BDOR::importerReservations(LecteurFichier* lecteur) {
    for (string category : lecteur->_cles) {
        vector<string>* noms = lecteur->obtenirDonnees(category, "m_nom");
        vector<string>* prix = lecteur->obtenirDonnees(category, "m_prixUnitaire");
        if (category == lecteur->_cles[0]) {
            auto desc = lecteur->obtenirDonnees(category, "m_jourPrevuDepart");
            for (int i = 0; i < noms->size(); i++) {
                reservations[category].push_back(Reservation(noms->operator[](i), desc->operator[](i), stod(prix->operator[](i))));
                cout << "Entree " << noms->operator[](i) << " " << desc->operator[](i) << " rattachee a la categorie " << category << " creee!" << endl;
                nombreOffres++;
            }
        }
        else {
            for (int i = 0; i < noms->size(); i++) {
                reservations[category].push_back(Reservation(noms->operator[](i), "", stod(prix->operator[](i))));
                cout << "Entree " << noms->operator[](i) << " rattachee a la categorie " << category << " creee!" << endl;
                nombreOffres++;
            }
        }
    }
    delete lecteur; 
}

int BDOR::getNombreOffres() const {
    return nombreOffres;
}
       

