#pragma once
#include "AbstractBDOR.h"
class BDOR : public AbstractBDOR
{
private:
	std::map<std::string, std::vector<Reservation>> reservations;
protected:
	BDOR();
public:
	virtual const std::vector<Reservation>& acceder(std::string) override;
};

