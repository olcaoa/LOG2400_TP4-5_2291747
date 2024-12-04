#pragma once
#include "BDOR.h"
class BDORProxy : public AbstractBDOR
{
public:
	BDORProxy();
	~BDORProxy() = default;
	int getNombreOffres() const override;
private:
	BDOR* _bdor;
	virtual std::vector<Reservation>& acceder(std::string) override;
};

