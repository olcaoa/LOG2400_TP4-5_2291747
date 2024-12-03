#pragma once
#include "LecteurFichier.h"
#include "Reservation.h"

class AbstractBDOR
{
private:
	virtual const std::vector<Reservation>& acceder(std::string) = 0;
public:
	const std::vector<Reservation>& operator[](std::string);
	virtual ~AbstractBDOR() = default;
};

