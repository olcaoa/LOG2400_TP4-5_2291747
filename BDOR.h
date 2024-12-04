#pragma once
#include "AbstractBDOR.h"
#include "LecteurFichier.h"
#include <map>
#include <vector>
#include <string>
#include "ReservationRabais.h"

class BDOR : public AbstractBDOR {
private:
    double dernierFacteurAjustement = 1;
    int nombreOffres = 0;
    void accept(ImprimeurReservation& log);
    std::map<std::string, std::vector<Reservation>> reservations;
	double convertirPrix(const std::string& devise, double prix);
protected:
    void liberer();
    LecteurFichier* _lecteur;
    BDOR();
    
public:
    void ajusterPrix(double facteur) override;
    void ajouterRabais(Reservation& r, std::string categorie, double rabais) override;
    ~BDOR();
    std::vector<Reservation>& acceder(std::string) override;
    void importerReservations(LecteurFichier* lecteur);
    int getNombreOffres() const override;
    static BDOR& getInstance();
    friend class ImprimeurReservation;
};
