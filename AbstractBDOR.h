#pragma once
#include "LecteurFichier.h"
#include "Reservation.h"

class AbstractBDOR
{
private:
	virtual std::vector<Reservation>& acceder(std::string) = 0;
public:
	~AbstractBDOR() = default;
	std::vector<Reservation>& operator[](std::string);
};

