#pragma once
#include "AbstractReservationDecoree.h"
#include "ImprimeurLoggeur.h"
class ReservationLoggeur : public ReservationComposite, public AbstractReservationDecoree
{
public:
	ReservationLoggeur& getReservation(std::string nom);
	ReservationLoggeur(AbstractReservation& r);
	const std::string& getNom() override;
	void accept(VisiteurImprimeur& visiteur) override;
	virtual void decorer() override;
	virtual AbstractReservation* clone() const override;
};

