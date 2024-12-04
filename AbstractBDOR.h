#pragma once
#include "LecteurFichier.h"
#include "Reservation.h"
#include "ImprimeurLoggeur.h"

class AbstractBDOR
{
private:
	virtual std::vector<Reservation>& acceder(std::string) = 0;
public:
	virtual void ajusterPrix(double facteur) = 0;
	virtual void ajouterRabais(Reservation& r, std::string categorie, double rabais) = 0;
	~AbstractBDOR() = default;
	virtual int getNombreOffres() const = 0;
	std::vector<Reservation>& operator[](std::string);
};

