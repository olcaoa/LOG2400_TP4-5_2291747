#pragma once
#include "BDOR.h"
class BDORProxy : public AbstractBDOR
{
public:
	BDORProxy();
private:
	BDOR* bdor;
	virtual const std::vector<Reservation>& acceder(std::string) override;
};

