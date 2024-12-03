#pragma once
#include "BDOR.h"
class BDORProxy : public AbstractBDOR
{
public:
	BDORProxy();
	~BDORProxy() = default;
private:
	BDOR* bdor;
	virtual std::vector<Reservation>& acceder(std::string) override;
};

