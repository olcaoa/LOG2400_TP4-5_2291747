#pragma once
#include "AbstractBDOR.h"
#include "LecteurFichier.h"
#include <map>
#include <vector>
#include <string>

class BDOR : public AbstractBDOR {
private:
    std::map<std::string, std::vector<Reservation>> reservations;
	double convertirPrix(const std::string& devise, double prix);
protected:
    void liberer();
    LecteurFichier* _lecteur;
    BDOR();
public:
    ~BDOR();
    static BDOR& getInstance();
    virtual std::vector<Reservation>& acceder(std::string) override;
    void importerReservations(LecteurFichier* lecteur);
};
