#pragma once
#include "LecteurFichier.h"
#include "Reservation.h"
#include "ImprimeurLoggeur.h"

class AbstractBDOR
{
private:
	virtual std::vector<Reservation>& acceder(std::string) = 0;
public:
	~AbstractBDOR() = default;
	virtual int getNombreOffres() const = 0;
	std::vector<Reservation>& operator[](std::string);
};

