#pragma once
#include "BDOR.h"
class BDORProxy : public AbstractBDOR
{
public:
	BDORProxy();
	~BDORProxy() = default;
	int getNombreOffres() const override;
	void ajusterPrix(double facteur) override;
	void ajouterRabais(Reservation& r, std::string categorie, double rabais) override;
private:
	BDOR* _bdor;
	virtual std::vector<Reservation>& acceder(std::string) override;
};

